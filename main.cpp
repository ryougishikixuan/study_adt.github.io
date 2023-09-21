#include"hw_currency.h"

int main() {
    currency cur1, cur2, cur3;
    cout << "请输入第一个金额（格式：+ 100 50）：";
    cin >> cur1;
    
    cout << "请输入第二个金额（格式：- 75 25）：";
    cin >> cur2;

    cur3 = cur1 + cur2;
    cout << "和为：";
    cur3.output();
    cout << endl;

    cur3 = cur1 % cur2;
    cout << "取余为：";
    cur3.output();
    cout << endl;

    cur3 = cur1 * cur2;
    cout << "乘积为：";
    cur3.output();
    cout <<endl;

    cur3 = cur1 / cur2;
    cout << "除法结果为：";
    cur3.output();
    cout << endl;

    cur3 = cur1 -cur2;
    cout << "减法结果为：";
    cur3.output();
    cout << endl;

    currency cur;
    cur = 12345;        
    cur.output();
    cur = 123.45;       
    cur.output();

    return 0;
}
