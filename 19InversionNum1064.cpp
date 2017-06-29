#include<iostream>
using namespace std;
//pore at problem please!!
int main()
{
    for(int i=1000; i<10000; i++)
    {
        int m=0,n=i;
        while(n!=0)
        {
            m=m*10+n%10;//critical!!!
            n=n/10;
        }
        if(m==i*9)
            cout<<i<<endl;
    }
    return 0;

}
