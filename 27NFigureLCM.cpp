#include<iostream>
using namespace std;
//如果没有按照题目要求设置范围的话会出现wrong answer！
//考虑问题不要太复杂，能不用数组就不用。数组初始化只能用常量表示范围
long int gcd(long int a,long int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            long int a,b;
            cin>>m>>a;
            m--;

            while(m!=0)
            {
                cin>>b;
                a=a*b/gcd(a,b);
                m--;
            }
            cout<<a<<endl;
        }
    }
    return 0;
}
