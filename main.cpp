#include"hw_currency.h"

int main() {
    currency cur1, cur2, cur3;
    cout << "�������һ������ʽ��+ 100 50����";
    cin >> cur1;
    
    cout << "������ڶ�������ʽ��- 75 25����";
    cin >> cur2;

    cur3 = cur1 + cur2;
    cout << "��Ϊ��";
    cur3.output();
    cout << endl;

    cur3 = cur1 % cur2;
    cout << "ȡ��Ϊ��";
    cur3.output();
    cout << endl;

    cur3 = cur1 * cur2;
    cout << "�˻�Ϊ��";
    cur3.output();
    cout <<endl;

    cur3 = cur1 / cur2;
    cout << "�������Ϊ��";
    cur3.output();
    cout << endl;

    cur3 = cur1 -cur2;
    cout << "�������Ϊ��";
    cur3.output();
    cout << endl;

    currency cur;
    cur = 12345;        
    cur.output();
    cur = 123.45;       
    cur.output();

    return 0;
}
