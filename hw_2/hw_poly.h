#ifndef HW_POLY.H
#define HW_POLY.H
#include <iostream>
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
    Node* prev;
    Node* next;
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
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        }

    //��Ա����
    //1.���ӽڵ�(β)
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
    //2.���ӽڵ�(ͷ)
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
    //3.��ֵ��ѯ�ڵ�
     Node* search(const T& val) {
        Node* current = head;
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
        Node* deleteNode = search(val); 
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
        Node* updateNode = search(val); 
        if (updateNode != nullptr) {
            // �ҵ�ƥ��ֵ�Ľڵ㣬���½ڵ��ֵΪnewval
            updateNode->data = newval;
        } else {
            // û���ҵ�ƥ��ֵ�Ľڵ㣬����½ڵ㣬ֵΪnewval
            append(newval);
        }
    }
    

    private:
    Node* head;
    Node* tail;
};











#endif HW_POLY.H
