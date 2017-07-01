#include<iostream>
#include<cmath>
using namespace std;
bool judge(int n)
{
    if(n<=1) return false;
    int m=(int)sqrt(n)+1;//m为枚举上届，+1是为了宁可多枚举一个，也不能放过一个
    for(int j=2;j<m;j++)
    {
        if(n%j==0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(judge(n))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
