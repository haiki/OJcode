#include<iostream>
using namespace std;
#define INF 0x7fffffff
int min_num(int a,int b)
{
    return a<b?a:b;
}
struct coin
{
    int wei;
    int val;

} buf[501];

int dp[10001];

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int emp,ful,n;
        cin>>emp>>ful>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>buf[i].val>>buf[i].wei;
        }
        int cur=ful-emp;//背包的实际体积
        for(int i=0; i<=cur; i++)
        {
            dp[i]=INF;//因为要求装满，所以将除了第0项的都初始化为无穷或者不存在：即-1。
        }
        dp[0]=0;//当容积为0时价值也为0
        for(int i=1; i<=n; i++)
        {
            for(int j=buf[i].wei; j<=cur; j++)//因为要利用前面已经改变的值。所以这里的循环是顺序的
            {
                /*if(dp[j]>dp[j-buf[i].wei]+buf[i].val)
                    dp[j]=dp[j-buf[i].wei]+buf[i].val;*///这样写好像有问题
                if(dp[j-buf[i].wei]!=INF)//只有这样才可以由前一个状态转移出当前状态，否则就保持原来的值，和dp[i-1]一样
                {
                    dp[j]=min_num(dp[j],dp[j-buf[i].wei]+buf[i].val);//选出比较小的那个
                }

            }
        }
        if(dp[cur]!=INF)
            cout<<"The minimum amount of money in the piggy-bank is "<<dp[cur]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;


    }
    return 0;
}

