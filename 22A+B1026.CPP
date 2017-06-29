#include<iostream>
#include<stack>
//#include<cmath>
using namespace std;
int main()
{
    long long int a,b,c=0;//16位字长，long 的取值范围：(-2^31_2^31-1),但是两个数相加有可能大于long，所以设置为long long~
    int m;//jinzhi

    while(cin>>m>>a>>b&&m!=0)
    {
        stack<int>s;
        c=a+b;
        while(c/m!=0)
        {
            s.push(c%m);
            c=c/m;
        }
        s.push(c);
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
            }
            cout<<endl;
    }
    return 0;
}
