#include<iostream>
using namespace std;
#define M 200907
//������ģ��������ʣ���a+b��mod N = (a mod N + b mod N)mod N;
//���ö������ݵ��������ȱ����еĵ�n��  an=a1*q^(k-1);
int fun(long long a,long long q,long long n)
{
    long long res=a;
    while(n!=0)//�Ǵ����������㣬Ҫ�������Ҫ�ı�����ĸ�����
    {
        if(n&1)
        {
            res*=q;
            res%=M;
        }
        n>>=1;
        q=(q*q)%M;
    }

     return res;
}
int main()
{
    int n;
    while(cin>>n)
    {
            for(int i=0;i<n;i++)
            {
            long long a,b,c,k;
            long long  q=0;
            cin>>a>>b>>c>>k;
            if(2*b==a+c)
            {
                long long ans=0;
                q=b-a;
                ans=(a%M+(((k-1)%M)*(q%M))%M)%M;
                cout<<ans<<endl;
            }
            else
            {
                q=b/a;
                cout<<fun(a,q,k-1)<<endl;
                //cout<<ans<<endl;

            }
        }

    }
    return 0;
}
