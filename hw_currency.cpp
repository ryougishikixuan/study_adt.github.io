#include <iostream>
using namespace std;

enum signType { plus, minus };

class currency {
public:
//构造函数
     currency(signType theSign = signType::plus, unsigned long theDollars = 0, unsigned int theCents = 0) {
        // 计算总金额并存储到 amount 中
        long newAmount = static_cast<long>(theDollars) * 100 + theCents;

        // 根据符号进行调整
        if (theSign == signType::minus) {
            newAmount = -newAmount;
        }

        amount = newAmount;
    }
//析构函数
    ~currency() = default;

    void setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
    
    long newAmount = static_cast<long>(theDollars) * 100 + theCents;

    
    if (theSign == signType::minus) {
        newAmount = -newAmount;
    }

    amount = newAmount;
}

    void setValue(double value) {
    
    long newAmount = static_cast<long>(value * 100);

    
    signType newSign = signType::plus;

    
    if (newAmount < 0) {
        newSign = signType::minus;
        newAmount = -newAmount;
    }

    amount = newAmount;
}

    signType getSign() const {
        if (amount < 0) return signType::minus;
        else return signType::plus;
    
    }
    unsigned long getDollars() const {
        if (amount < 0) return (-amount) / 100;
        else return amount / 100;
    }
    unsigned int getCents() const {
        if (amount < 0) return -amount - getDollars() * 100;
        else return amount - getDollars() * 100;
    }

    currency operator+(const currency&) const;
    currency operator+=(const currency& x) {
        amount += x.amount;
        return *this;
    }

//>>运算符重载的友元函数
    friend istream& operator>>(istream& in, currency& cur);

// 重载-  % * 和 / 运算符

    currency operator%(const currency& x) const;
    currency operator*(const currency& x) const;
    currency operator/(const currency& x) const;
    currency operator-(const currency& x) const;
    currency operator-=(const currency& x){
         amount -= x.amount;
        return *this;
    };
    void output(ostream&) const;

//重载=运算符
    currency& operator=(int x) {
        
        signType newSign = (x < 0) ? signType::minus : signType::plus;
        unsigned long newDollars = (x < 0) ? (-x) / 100 : x / 100;
        unsigned int newCents = (x < 0) ? (-x) % 100 : x % 100;
        
        setValue(newSign, newDollars, newCents);
        return *this;
    }

// 重载 = 运算符，double x 作为参数
    currency& operator=(double x) {
        
        long amountInCents = static_cast<long>(x * 100);

        signType newSign = (amountInCents < 0) ? signType::minus : signType::plus;
        unsigned long newDollars = (amountInCents < 0) ? (-amountInCents) / 100 : amountInCents / 100;
        unsigned int newCents = (amountInCents < 0) ? (-amountInCents) % 100 : amountInCents % 100;

        setValue(newSign, newDollars, newCents);
        return *this;
    }    

private:
    long amount;
};

//定义>>运算符
istream& operator>>(istream& in, currency& cur) {

    char sign ;
    unsigned long dollars ;
    unsigned int cents ;

    in >> sign >> dollars >> cents;

    if (sign == signType::minus) {
        cur.setValue(signType::minus, dollars, cents);
    } else {
        cur.setValue(signType::plus, dollars, cents);
    }

    return in;
}

// 定义 % 运算符
currency currency::operator%(const currency& x) const {
    long remainder = amount % x.amount;
    return currency(getSign(), remainder / 100, remainder % 100);
}

// 定义 * 运算符
currency currency::operator*(const currency& x) const {
    long result = amount * x.amount;
    return currency(getSign(), result / 100, result % 100);
}

// 定义 / 运算符
currency currency::operator/(const currency& x) const {
    if (x.amount == 0) {
        // 处理除零错误
        std::cerr << "除数不能为零\n";
        return currency();
    }

    long result = amount / x.amount;
    return currency(getSign(), result / 100, result % 100);
}
//定义-运算符
currency currency::operator-(const currency& x) const {
    long result = amount - x.amount;
    return currency(getSign(), result / 100, result % 100);
}
currency currency::operator+(const currency& x) const {
    long result = amount + x.amount;
    return currency(getSign(), result / 100, result % 100);
}

// 定义输出函数
void currency::output(ostream& out=cout) const {
    if (getSign() == signType::minus) {
        out << '-';
    }
    out << "$" << getDollars() << "." << getCents();
}

int main() {
    currency cur1, cur2, cur3;
    cout << "请输入第一个货币金额（格式：+ 100 50）：";
    cin >> cur1;
    
    cout << "请输入第二个货币金额（格式：- 75 25）：";
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
