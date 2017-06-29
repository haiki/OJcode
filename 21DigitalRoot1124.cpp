#include<iostream>
#include<cstring>
//设置变量的时候请设置初值  求你了！！
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
    while(cin>>n&&n!="0")//why "0"?'0' ok?就是n！=字符串0的意思。后者是字符
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
