#ifndef HW_POLY_H
#define HW_POLY_H
#include<iostream>
#include <utility>
#include <sstream>
using namespace std;
//需要使用双链表结构实现多项式的加减 
//使用双链表是因为我希望进行双链表的熟悉和学习

/*双链表的结构
1.每个节点有头指针和尾指针和数据域
2.在进行插入操作时,要保证后续节点先于插入节点联系,防止丢失后续节点
*/

/*多项式加减的注意事项
1.需要有2个构造函数(默认,含参,拷贝)
2.构造函数需要有异常处理能力
3.需要有一个output功能输出多项式的内容
*/

//定义双链表节点
template<class T>
struct Node
{
    //属性
    T data;
    Node<T>* prev;
    Node<T>* next;
    //构造,析构
    Node(T val):data(val),prev(nullptr),next(nullptr){}
    ~Node()=default;
};

//定义双链表
template<class T>
class doubleLinkList{
    public:
    //构造函数
    doubleLinkList():head(nullptr),tail(nullptr){}
    //析构函数
    ~doubleLinkList(){ 
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        cout<<"doubleLinkList destruction done"<<endl;
        }
    
    //成员方法
    //1.增加节点(尾)
    void append(T val){
        Node<T>* newNode = new Node<T>(val);
          if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } 
    }
    //2.增加节点(头)
    void preappend(T val){
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    //3.按值查询节点
     Node<T>* search(const T& val) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return current; // 找到匹配值，返回节点指针
            }
            current = current->next;
        }
        return nullptr; // 没有找到匹配值，返回 nullptr
    }
    //4.按值删除节点
    void remove(const T& val) {
        Node<T>* deleteNode = search(val); 
            if (deleteNode == head) {
                // 删除的节点是头节点
                head = deleteNode->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else if (deleteNode == tail) {
                // 删除的节点是尾节点
                tail = deleteNode->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            } else {
                // 删除的节点在链表中间
                deleteNode->prev->next = deleteNode->next;
                deleteNode->next->prev = deleteNode->prev;
            }
            delete deleteNode; // 释放节点内存
        }
    //5.修改节点
    void update(const T& val, const T& newval) {
        Node<T>* updateNode = search(val); 
        if (updateNode != nullptr) {
            // 找到匹配值的节点，更新节点的值为newval
            updateNode->data = newval;
        } else {
            // 没有找到匹配值的节点，添加新节点，值为newval
            append(newval);
        }
    }
     
    Node<T>* head;
    Node<T>* tail;
};

//定义多项式

class polys{
    public:
    //三种构造函数(默认,含参,拷贝)
    polys():poly(new doubleLinkList<pair<int,int>>()){}
    polys(const doubleLinkList<pair<int,int>> & valPoly):poly(new doubleLinkList<pair<int,int>>(valPoly)){}
    polys(const polys& other) {
    this->poly = new doubleLinkList<pair<int,int>>(*other.poly);
    }
    //析构函数
    ~polys()=default;
    /*成员函数:
    0.写入多项式
    1.删除多项式
    2.修改多项式
    3.output多项式
    4.多项式相加(重载+)
    5.多项式相减(重载-)
    */
    //0.写入
    void input() {
        // 提示用户
    cout << "请输入多项式的系数和指数(以逗号分隔,eg:12 2,45 6,-23 3即为12x^2+45x^6-23x^3 ): ";
    string inputLine;
    getline(cin, inputLine); // 使用getline方法读取输入

    istringstream inputStream(inputLine);
    string token;
        // 分割字符串这个操作在while的条件表达式已经完成了,getline方法真好用=)
    while (getline(inputStream, token, ',')) {
        istringstream pairStream(token);
        int coefficient, exponent;

        // 将系数和指数解析为整数，并创建一个pair
        if (pairStream >> coefficient >> exponent) {
            poly->append(std::make_pair(coefficient, exponent));
        } else {
            cout << "多项式输入错误: " << token << endl;
        }
    }
    return;
    }
    //1.删除
    void remove(){
        this->~polys();
        return;
    }
    //2.修改
    void update(){
        //初始化poly再重新调用input()写入一次
        this->poly= new doubleLinkList<pair<int,int>>();
        this->input();
        return;
    }
    //3.output
    void output(){
        //读取this->poly,假设读取到pair值为(2,3)则生成字符串"2x^3",当读取完poly所有的元素后,将这些字符串拼接起来,比如poly内有(2,3),(-5,6)两个节点,则输出"2x^3-5x^6"
        Node<pair<int, int>>* current = poly->head;

        if (current == nullptr) {
        cout << "多项式为空" << endl;
        return;
        }

        bool isFirstTerm = true; // 用于判断是否是第一个项

        while (current != nullptr) {
        int coefficient = current->data.first;
        int exponent = current->data.second;

        if (!isFirstTerm) {
            if (coefficient >= 0) {
                cout << "+"; // 如果系数是正数，添加正号
            }
        } else {
            isFirstTerm = false;
        }
        // 输出系数
        if (coefficient != 1 && coefficient != -1) {
            cout << coefficient;
        } else if (coefficient == -1) {
            cout << "-";
        }
        // 输出指数
        cout << "x^" << exponent;
        current = current->next;
        }

        cout << endl;
    }
    //4.多项式相加
    //两个多项式相加产生一个新的结果多项式
    //需要按值匹配相应的exponent,如果没有匹配就直接将这个节点加入结果多项式,如果匹配成功就coefficient进行相加,再把结果加入结果多项式
    polys* puls(const polys &p1) {
    polys* result = new polys(); // 创建结果多项式对象

    Node<pair<int, int>>* currentThis = poly->head;
    Node<pair<int, int>>* currentP1 = p1.poly->head;

    while (currentThis != nullptr || currentP1 != nullptr) {
        int coefficientThis = 0;
        int coefficientP1 = 0;
        int exponent = 0;

        // 获取当前节点的系数和指数
        if (currentThis != nullptr) {
            coefficientThis = currentThis->data.first;
            exponent = currentThis->data.second;
        }

        if (currentP1 != nullptr) {
            coefficientP1 = currentP1->data.first;
            exponent = currentP1->data.second;
        }

        // 如果两个节点的指数相等，则将系数相加
        if (currentThis != nullptr && currentP1 != nullptr && currentThis->data.second == currentP1->data.second) {
            int sumCoefficient = coefficientThis + coefficientP1;
            // 如果系数不为0，则将结果插入到结果多项式中
            if (sumCoefficient != 0) {
                result->poly->append(std::make_pair(sumCoefficient, exponent));
            }
            currentThis = currentThis->next;
            currentP1 = currentP1->next;
        } else if ((currentThis != nullptr && currentThis->data.second > currentP1->data.second) || currentP1 == nullptr) {
            // 如果当前多项式的指数大于另一个多项式，或者另一个多项式已经结束，则将当前多项式的项插入结果中
            result->poly->append(std::make_pair(coefficientThis, exponent));
            currentThis = currentThis->next;
        } else if ((currentThis != nullptr && currentThis->data.second < currentP1->data.second) || currentThis == nullptr) {
            // 如果当前多项式的指数小于另一个多项式，或者当前多项式已经结束，则将另一个多项式的项插入结果中
            result->poly->append(std::make_pair(coefficientP1, exponent));
            currentP1 = currentP1->next;
        }
    }
    cout<<"相加结果为:";
    result->output();
    cout<<endl;
    return result;
    }

        // 多项式相减函数
        polys* subtraction(const polys &p1) {
        polys* result = new polys(); // 创建结果多项式对象

        Node<pair<int, int>>* currentThis = poly->head;
        Node<pair<int, int>>* currentP1 = p1.poly->head;

        while (currentThis != nullptr || currentP1 != nullptr) {
            int coefficientThis = 0;
            int coefficientP1 = 0;
            int exponentThis = 0;
            int exponentP1 = 0;

        // 获取当前节点的系数和指数
        if (currentThis != nullptr) {
            coefficientThis = currentThis->data.first;
            exponentThis = currentThis->data.second;
        }

        if (currentP1 != nullptr) {
            coefficientP1 = currentP1->data.first;
            exponentP1 = currentP1->data.second;
        }

        // 比较当前项的指数
        if (exponentThis == exponentP1) {
            int diffCoefficient = coefficientThis - coefficientP1;
            // 如果系数不为0，则将结果插入到结果多项式中
            if (diffCoefficient != 0) {
                result->poly->append(std::make_pair(diffCoefficient, exponentThis));
            }
            currentThis = currentThis->next;
            currentP1 = currentP1->next;
        } else if (exponentThis > exponentP1 || currentP1 == nullptr) {
            // 如果当前多项式的指数大于另一个多项式，或者另一个多项式已经结束，则将当前多项式的项插入结果中
            result->poly->append(std::make_pair(coefficientThis, exponentThis));
            currentThis = currentThis->next;
        } else if (exponentThis < exponentP1 || currentThis == nullptr) {
            // 如果当前多项式的指数小于另一个多项式，或者当前多项式已经结束，则将另一个多项式的项插入结果中
            result->poly->append(std::make_pair(-coefficientP1, exponentP1));
            currentP1 = currentP1->next;
        }
        }

        cout << "相减结果为:";
        result->output();
        cout << endl;
        return result;
    }


    private:
    doubleLinkList<pair<int,int>>* poly;
};








#endif
