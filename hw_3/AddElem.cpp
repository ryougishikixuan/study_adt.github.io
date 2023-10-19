#include "C.h"
#include "SqList.h"
typedef int T;
#include "Func1_1.h"


void addElem(SqList<T>& La, const SqList<T>& Lb) {
    // ���� Lb 
    for (int i = 0; i < Lb.ListLength(); i++) {
        T elem;
        Lb.GetElem(i, elem);

        // �ж� elem �Ƿ��� La �У������������뵽 La ��
        if (La.LocateElem(elem, equal)==-1) {
            
            La.ListInsert(La.ListLength(), elem);
        }
    }
}
int main() {
    SqList<int> La(10);
    SqList<int> Lb(5);

    
    La.ListInsert(0, 1);
    La.ListInsert(1, 2);
    La.ListInsert(2, 3);

    
    Lb.ListInsert(0, 2);
    Lb.ListInsert(1, 4);
    Lb.ListInsert(2, 5);

    cout << "La=";
    La.ListTraverse(print);

    cout << "Lb=";
    Lb.ListTraverse(print);

    addElem(La, Lb);

    cout << "La ���Ӻ�=";
    La.ListTraverse(print);

    return 0;
}
