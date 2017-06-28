#include<iostream>
using namespace std;
int main()
{
    int a,b,k;
    while(cin>>a>>b>>k)
    {
        if(a==0||b==0)
            return 0;
        int result=a+b;
        bool flag = true;
        for(int i=0;i<k;i++)
        {
            int a1=a%10;
            a=a/10;
            int b1=b%10;
            b=b/10;
            if(a1==b1)
            {
                continue;
            }
            else
            {
                flag=false;
                break;
            }

        }
        if(flag)
            cout<<"-1"<<endl;
        else
            cout<<result<<endl;

    }
    return 0;
}
