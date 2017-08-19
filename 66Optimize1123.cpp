
#include<iostream>
using namespace std;
int max_num(int a,int b)
{
    return a>b?a:b;
}
int dp[1001];//有i个物品在j个体积中的最大价值
struct pack
{
    int val;
    int ti;
} buf[101]; //一共有多少株草药
int main()
{
    int t,m;
    while(cin>>t>>m)
    {
        for(int i=1; i<=m; i++)
        {
            cin>>buf[i].ti>>buf[i].val;
        }
        for(int i=0; i<=t; i++)
        {
            dp[i]=0;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=t; j>=buf[i].ti; j--)
            {
                dp[j]= max_num(dp[j],dp[j-buf[i].ti]+buf[i].val);
                //用倒序的方法可以在不改变前面的i-1的前提下对现在的状态进行操作，而且省去了再循环j<buf[i].ti的操作
            }

        }
        cout<<dp[t]<<endl;
    }

    return 0;
}
