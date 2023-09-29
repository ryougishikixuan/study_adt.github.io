#include <iostream>
#include"hw_currency.h"




//���캯��

     currency::currency(signType theSign, unsigned long theDollars , unsigned int theCents ) {
        // �����ܽ��洢�� amount ��
        long newAmount = static_cast<long>(theDollars) * 100 + theCents;

        // ���ݷ��Ž��е���
        if (theSign == signType::minus) {
            newAmount = -newAmount;
        }

        amount = newAmount;
    }
//�������캯��
    currency::currency(const currency& other) {
    this->amount = other.amount;
}



    void currency::setValue(signType theSign, unsigned long theDollars, unsigned int theCents) {
    
    long newAmount = static_cast<long>(theDollars) * 100 + theCents;

    
    if (theSign == signType::minus) {
        newAmount = -newAmount;
    }

    amount = newAmount;
}

    void currency::setValue(double value) {
    
    long newAmount = static_cast<long>(value * 100);

    
    signType newSign = signType::plus;

    
    if (newAmount < 0) {
        newSign = signType::minus;
        newAmount = -newAmount;
    }

    amount = newAmount;
}

    signType currency::getSign() const {
        if (amount < 0) return signType::minus;
        else return signType::plus;
    
    }
    unsigned long currency::getDollars() const {
        if (amount < 0) return (-amount) / 100;
        else return amount / 100;
    }
    unsigned int currency::getCents() const {
        if (amount < 0) return -amount - getDollars() * 100;
        else return amount - getDollars() * 100;
    }

    
    currency currency::operator+=(const currency& x) {
        amount += x.amount;
        return *this;
    }





    
    currency currency::operator-=(const currency& x){
         amount -= x.amount;
        return *this;
    };
    

//����=�����
    currency& currency::operator=(int x) {
        
        signType newSign = (x < 0) ? signType::minus : signType::plus;
        unsigned long newDollars = (x < 0) ? (-x) / 100 : x / 100;
        unsigned int newCents = (x < 0) ? (-x) % 100 : x % 100;
        
        setValue(newSign, newDollars, newCents);
        return *this;
    }

// ���� = �������double x ��Ϊ����
    currency& currency::operator=(double x) {
        
        long amountInCents = static_cast<long>(x * 100);

        signType newSign = (amountInCents < 0) ? signType::minus : signType::plus;
        unsigned long newDollars = (amountInCents < 0) ? (-amountInCents) / 100 : amountInCents / 100;
        unsigned int newCents = (amountInCents < 0) ? (-amountInCents) % 100 : amountInCents % 100;

        setValue(newSign, newDollars, newCents);
        return *this;
    }    



//����>>�����
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

// ���� % �����
currency currency::operator%(const currency& x) const {
    long remainder = amount % x.amount;
    return currency(getSign(), remainder / 100, remainder % 100);
}

// ���� * �����
currency currency::operator*(const currency& x) const {
    long result = amount * x.amount;
    return currency(getSign(), result / 100, result % 100);
}

// ���� / �����
currency currency::operator/(const currency& x) const {
    if (x.amount == 0) {
        // ����������
        std::cerr << "��������Ϊ��\n";
        return currency();
    }

    long result = amount / x.amount;
    return currency(getSign(), result / 100, result % 100);
}
//����-�����
currency currency::operator-(const currency& x) const {
    long result = amount - x.amount;
    return currency(getSign(), result / 100, result % 100);
}
currency currency::operator+(const currency& x) const {
    long result = amount + x.amount;
    return currency(getSign(), result / 100, result % 100);
}

// �����������
void currency::output(ostream& out) const {
    if (getSign() == signType::minus) {
        out << '-';
    }
    out << "$" << getDollars() << "." << getCents();
}

