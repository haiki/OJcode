#include<iostream>
using namespace std;
//��n���ķֽ��Ǳ���Ŀ�Ĺؼ���
bool mark[1001];//ȫ�ֱ������������false
int prime[1001];
int cnt1[1010];//n�������ÿ�������ĸ���
int cnt2[1010];//a��ÿ�������ĸ���
int prime_size=0;
void init()
{
    for(int i=2;i<=1000;i++)
    {
        if(mark[i]==true)continue;
        mark[i]=true;
        prime[prime_size++]=i;
        for(int j=i*i;j<=1000;j+=i)
            mark[j]=true;
    }
}
int main()
{
    init();
    int a,n;
    while(cin>>n>>a)
    {
        for(int i=0;i<prime_size;i++)
            cnt1[i]=cnt2[i]=0;
        for(int j=0;j<prime_size;j++)
        {
           int t=n;//ΪʲôҪ��ֵ������һ����
            while(t)
            {
                cnt1[j]+=t/prime[j];
                t=t/prime[j];
            }
           /* while(n)
            {
                cnt1[j]+=n/prime[j];
                n=n/prime[j];
            }*/
        }
         int ans=123456789;
        for(int j=0;j<prime_size;j++)
         {
             while(a%prime[j]==0)
            {
                cnt2[j]++;
                a=a/prime[j];
            }
            if(cnt2[j]==0)continue;//critical �ô���һ��Ҫע�⿴�Ƿ����ʹ����Ϊ0
            if(cnt1[j]/cnt2[j]<ans)
                {ans=cnt1[j]/cnt2[j];}
         }

      cout<<ans<<endl;


    }
    return 0;


}
