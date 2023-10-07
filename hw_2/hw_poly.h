#ifndef HW_POLY_H
#define HW_POLY_H
#include<iostream>
#include <utility>
#include <sstream>
using namespace std;
//��Ҫʹ��˫����ṹʵ�ֶ���ʽ�ļӼ� 
//ʹ��˫��������Ϊ��ϣ������˫�������Ϥ��ѧϰ

/*˫����Ľṹ
1.ÿ���ڵ���ͷָ���βָ���������
2.�ڽ��в������ʱ,Ҫ��֤�����ڵ����ڲ���ڵ���ϵ,��ֹ��ʧ�����ڵ�
*/

/*����ʽ�Ӽ���ע������
1.��Ҫ��2�����캯��(Ĭ��,����,����)
2.���캯����Ҫ���쳣��������
3.��Ҫ��һ��output�����������ʽ������
*/

//����˫����ڵ�
template<class T>
struct Node
{
    //����
    T data;
    Node<T>* prev;
    Node<T>* next;
    //����,����
    Node(T val):data(val),prev(nullptr),next(nullptr){}
    ~Node()=default;
};

//����˫����
template<class T>
class doubleLinkList{
    public:
    //���캯��
    doubleLinkList():head(nullptr),tail(nullptr){}
    //��������
    ~doubleLinkList(){ 
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }
        cout<<"doubleLinkList destruction done"<<endl;
        }
    
    //��Ա����
    //1.���ӽڵ�(β)
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
    //2.���ӽڵ�(ͷ)
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
    //3.��ֵ��ѯ�ڵ�
     Node<T>* search(const T& val) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == val) {
                return current; // �ҵ�ƥ��ֵ�����ؽڵ�ָ��
            }
            current = current->next;
        }
        return nullptr; // û���ҵ�ƥ��ֵ������ nullptr
    }
    //4.��ֵɾ���ڵ�
    void remove(const T& val) {
        Node<T>* deleteNode = search(val); 
            if (deleteNode == head) {
                // ɾ���Ľڵ���ͷ�ڵ�
                head = deleteNode->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else if (deleteNode == tail) {
                // ɾ���Ľڵ���β�ڵ�
                tail = deleteNode->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            } else {
                // ɾ���Ľڵ��������м�
                deleteNode->prev->next = deleteNode->next;
                deleteNode->next->prev = deleteNode->prev;
            }
            delete deleteNode; // �ͷŽڵ��ڴ�
        }
    //5.�޸Ľڵ�
    void update(const T& val, const T& newval) {
        Node<T>* updateNode = search(val); 
        if (updateNode != nullptr) {
            // �ҵ�ƥ��ֵ�Ľڵ㣬���½ڵ��ֵΪnewval
            updateNode->data = newval;
        } else {
            // û���ҵ�ƥ��ֵ�Ľڵ㣬����½ڵ㣬ֵΪnewval
            append(newval);
        }
    }
    

    
    Node<T>* head;
    Node<T>* tail;
};

//�������ʽ

class polys{
    public:
    //���ֹ��캯��(Ĭ��,����,����)
    polys():poly(new doubleLinkList<pair<int,int>>()){}
    polys(const doubleLinkList<pair<int,int>> & valPoly):poly(new doubleLinkList<pair<int,int>>(valPoly)){}
    polys(const polys& other) {
    this->poly = new doubleLinkList<pair<int,int>>(*other.poly);
    }
    //��������
    ~polys()=default;
    /*��Ա����:
    0.д�����ʽ
    1.ɾ������ʽ
    2.�޸Ķ���ʽ
    3.output����ʽ
    4.����ʽ���(����+)
    5.����ʽ���(����-)
    */
    //0.д��
    void input() {
        // ��ʾ�û�
    cout << "���������ʽ��ϵ����ָ��(�Զ��ŷָ�,eg:12 2,45 6,-23 3��Ϊ12x^2+45x^6-23x^3 ): ";
    string inputLine;
    getline(cin, inputLine); // ʹ��getline������ȡ����

    istringstream inputStream(inputLine);
    string token;
        // �ָ��ַ������������while���������ʽ�Ѿ������,getline���������=)
    while (getline(inputStream, token, ',')) {
        istringstream pairStream(token);
        int coefficient, exponent;

        // ��ϵ����ָ������Ϊ������������һ��pair
        if (pairStream >> coefficient >> exponent) {
            poly->append(std::make_pair(coefficient, exponent));
        } else {
            cout << "����ʽ�������: " << token << endl;
        }
    }
    return;
    }
    //1.ɾ��
    void remove(){
        this->~polys();
        return;
    }
    //2.�޸�
    void update(){
        //��ʼ��poly�����µ���input()д��һ��
        this->poly= new doubleLinkList<pair<int,int>>();
        this->input();
        return;
    }
    //3.output
    void output(){
        //��ȡthis->poly,�����ȡ��pairֵΪ(2,3)�������ַ���"2x^3",����ȡ��poly���е�Ԫ�غ�,����Щ�ַ���ƴ������,����poly����(2,3),(-5,6)�����ڵ�,�����"2x^3-5x^6"
        Node<pair<int, int>>* current = poly->head;

        if (current == nullptr) {
        cout << "����ʽΪ��" << endl;
        return;
        }

        bool isFirstTerm = true; // �����ж��Ƿ��ǵ�һ����

        while (current != nullptr) {
        int coefficient = current->data.first;
        int exponent = current->data.second;

        if (!isFirstTerm) {
            if (coefficient >= 0) {
                cout << "+"; // ���ϵ�����������������
            }
        } else {
            isFirstTerm = false;
        }
        // ���ϵ��
        if (coefficient != 1 && coefficient != -1) {
            cout << coefficient;
        } else if (coefficient == -1) {
            cout << "-";
        }
        // ���ָ��
        cout << "x^" << exponent;
        current = current->next;
        }

        cout << endl;
    }

    private:
    doubleLinkList<pair<int,int>>* poly;
};








#endif
