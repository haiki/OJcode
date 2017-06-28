#include<iostream>
using namespace std;
/*int main()
{
    int a,b;
    int buff1[11]={0},buff2[11]={0};
    while(cin>>a>>b)
    {
        int si1=0,si2=0;
        int result=0;
        while(a!=0)
        {
            buff1[si1++]=a%10;
            a=a/10;
        }
        while(b!=0)
        {
            buff2[si2++]=b%10;
            b=b/10;
        }
        for(int i=0;i<si1;i++)
        {
            for(int j=0;j<si2;j++)
            {
                result+=buff1[i]*buff2[j];
            }
        }
        cout<<result<<endl;

    }
    return 0;
}
*/
int main()
{
    char buff1[11],buff2[11];
    int result=0;
    while(cin>>buff1>>buff2)
    {
        for(int i=0;buff1[i]!='\0';i++)
            for(int j=0;buff2[j]!='\0';j++)
                result+=(buff1[i]-'0')*(buff2[j]-'0');
        cout<<result<<endl;
    }

    return 0;
}
