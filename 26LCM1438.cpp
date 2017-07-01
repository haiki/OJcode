#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    while(b!=0)
    {
        int tmp=a%b;
        a=b;
        b=tmp;
    }
    return a;

}
int main()
{
    int n1,n2,result=0;
    while(cin>>n1>>n2)
    {
        int m=n1*n2;
        int n=gcd(n1,n2);
        cout<<m/n<<endl;

    }
    return 0;
}
