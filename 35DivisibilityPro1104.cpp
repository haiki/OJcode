#include<iostream>
using namespace std;
//对n！的分解是本题目的关键。
bool mark[1001];//全局变量的情况下是false
int prime[1001];
int cnt1[1010];//n！里面的每个因数的个数
int cnt2[1010];//a中每个因数的个数
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
           int t=n;//为什么要赋值给另外一个？
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
            if(cnt2[j]==0)continue;//critical 敲代码一定要注意看是否会致使除数为0
            if(cnt1[j]/cnt2[j]<ans)
                {ans=cnt1[j]/cnt2[j];}
         }

      cout<<ans<<endl;


    }
    return 0;


}
