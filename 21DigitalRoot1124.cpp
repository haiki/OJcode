#include<iostream>
#include<cstring>
//���ñ�����ʱ�������ó�ֵ  �����ˣ���
using namespace std;
int Seperate1(string s)
{
    int sum=0,i=0;
    while(i<s.length())
    {
        sum+=s[i++]-'0';
    }
    return sum;

}
int Seperate2(int val)
{
    int sum=0;
    while(val!=0)
    {
        sum+=val%10;
        val=val/10;
    }
    return sum;
}

int main()
{
    string n;
    while(cin>>n&&n!="0")//why "0"?'0' ok?����n��=�ַ���0����˼���������ַ�
    {
        int num=Seperate1(n);
       // cout<<num<<endl;
        while(num>=10){
            num=Seperate2(num);
        }
        cout<<num<<endl;
    }
    return 0;
}
