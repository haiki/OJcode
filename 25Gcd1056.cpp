#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int n1,n2;
    while(cin>>n1>>n2)
    {
        cout<<gcd(n1,n2)<<endl;

    }
    return 0;
}
