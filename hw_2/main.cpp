#include"hw_poly.h"
int main(){
//����doubleLinkList
doubleLinkList<int> dll1;
dll1.append(2);
dll1.append(3);
dll1.append(4);
dll1.append(5);
dll1.append(6);
dll1.preappend(1);

dll1.remove(2);
Node<int>* node=dll1.search(4);
dll1.update(3,30);
dll1.~doubleLinkList();

//����poly�Ĺ���
polys p1;
p1.input();
p1.output();
p1.update();
p1.output();


return 0;
}