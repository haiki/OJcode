#include<iostream>
using namespace std;
int main()
{
    int a,b;
    while(cin>>a>>b)
   {
       int ans=1;
       if(a==0&&b==0)
            break;

    while(b!=0)
    {
        if(b&1)//��������������һ��
        {
            ans*=a;
            ans%=1000;
        }
        b>>=1;//����
        a*=a;
        a%=1000;//ȡa�ĺ���λ
    }
    cout<<ans<<endl;
   }
}

