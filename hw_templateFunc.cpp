#include<iostream>
//1.模板函数count ,返回值是数组a[0:n-1]的个数
template<typename T,size_t N>
size_t count(T (&arr)[N])
{
    return N;
}

//学习到的知识:
//1. 将数组对象的引用作为参数传入函数,编译器会在编译时就自行判断T的类型信息
//2. 编译器因为检索到N的size_t类型,会在编译时隐式的将数组的大小信息存入N中,不需要在函数中再进行计数

//测试
// int main(){
// int a[5]{1,2,3,4,5};
// int b[3]{6,7,8};
// std::cout<<"a:"<<count(a)<<std::endl;
// std::cout<<"b:"<<count(b)<<std::endl;
// }
//输出信息
//a:5
//b:3


//2.模板函数fill ,给数组a[start:end-1]赋值value
template<typename T,size_t N>
void fill(T (&arr)[N],T &value)
{
    for(int i=0;i<N;i++)
    {
        arr[i]=value;
    }
    return;
}

//测试
int main(){
    char a[4]{'a','b','c','d'};
    char value{'s'};
    fill(a,value);
    for(int i=0;i<4;i++)
    {
        std::cout<<a[i]<<" ";
    }
}
//输出信息
//s s s s






