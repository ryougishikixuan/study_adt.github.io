#include<iostream>
//1.ģ�庯��count ,����ֵ������a[0:n-1]�ĸ���
template<typename T,size_t N>
size_t count(T (&arr)[N])
{
    return N;
}

//ѧϰ����֪ʶ:
//1. ����������������Ϊ�������뺯��,���������ڱ���ʱ�������ж�T��������Ϣ
//2. ��������Ϊ������N��size_t����,���ڱ���ʱ��ʽ�Ľ�����Ĵ�С��Ϣ����N��,����Ҫ�ں������ٽ��м���

//����
// int main(){
// int a[5]{1,2,3,4,5};
// int b[3]{6,7,8};
// std::cout<<"a:"<<count(a)<<std::endl;
// std::cout<<"b:"<<count(b)<<std::endl;
// }
//�����Ϣ
//a:5
//b:3


//2.ģ�庯��fill ,������a[start:end-1]��ֵvalue
template<typename T,size_t N>
void fill(T (&arr)[N],T &value)
{
    for(int i=0;i<N;i++)
    {
        arr[i]=value;
    }
    return;
}

//����
int main(){
    char a[4]{'a','b','c','d'};
    char value{'s'};
    fill(a,value);
    for(int i=0;i<4;i++)
    {
        std::cout<<a[i]<<" ";
    }
}
//�����Ϣ
//s s s s






