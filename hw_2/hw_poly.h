#ifndef HW_POLY.H
#define HW_POLY.H
#include <iostream>
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
    Node* prev;
    Node* next;
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
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        }

    //成员方法
    //1.增加节点(尾)
    void append(T val){
        Node* newNode = new Node(val);
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
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    //3.按值查询节点
     Node* search(const T& val) {
        Node* current = head;
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
        Node* deleteNode = search(val); 
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
        Node* updateNode = search(val); 
        if (updateNode != nullptr) {
            // 找到匹配值的节点，更新节点的值为newval
            updateNode->data = newval;
        } else {
            // 没有找到匹配值的节点，添加新节点，值为newval
            append(newval);
        }
    }
    

    private:
    Node* head;
    Node* tail;
};











#endif HW_POLY.H
