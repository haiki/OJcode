#include<iostream>
using namespace std;
int main()
{
    for(int i=0;i<256;i++)
    {


        int k=0,n=0,m=0;
        k=n=i*i;
        while(n!=0)
        {
            m=m*10+n%10;
            n=n/10;
        }
        if(k==m)
            cout<<i<<endl;
    }
    return 0;
}
