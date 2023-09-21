#ifndef CURRENCY_H
#define CURRENCY_H
using namespace std;
#include <iostream>

enum signType { plus, minus };

class currency {
public:
    //构造函数
    currency(signType theSign = signType::plus, unsigned long theDollars = 0, unsigned int theCents = 0);
    currency(const currency& other); 

    //析构函数
    ~currency() = default;

    //属性set/get函数
    void setValue(signType theSign, unsigned long theDollars, unsigned int theCents);
    void setValue(double value);
    signType getSign() const;
    unsigned long getDollars() const;
    unsigned int getCents() const;
    //成员函数
    currency operator+(const currency&) const;
    currency operator+=(const currency& x);
    currency operator%(const currency& x) const;
    currency operator*(const currency& x) const;
    currency operator/(const currency& x) const;
    currency operator-(const currency& x) const;
    currency operator-=(const currency& x);
    void output(std::ostream& out = std::cout) const;
    currency& operator=(int x);
    currency& operator=(double x);

    //友元函数
    friend std::istream& operator>>(std::istream& in, currency& cur);

private:
    long amount;
};

std::istream& operator>>(std::istream& in, currency& cur);

#endif 
