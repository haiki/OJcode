#include<iostream>
using namespace std;
int max_num(int a,int b)
{
    return a>b?a:b;
}
int dp[101][1001];//��i����Ʒ��j������е�����ֵ
struct pack
{
    int val;
    int ti;
} buf[101]; //һ���ж������ҩ
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
            dp[0][i]=0;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=t; j>=buf[i].ti; j--)//��Ȼ���˵��򣬱����ͼ�����
            {
                dp[i][j]= max_num(dp[i-1][j],dp[i-1][j-buf[i].ti]+buf[i].val);
            }
            for(int k=buf[i].ti-1;k>=0;k--)
            {
                dp[i][k]=dp[i-1][k];
            }
        }
        cout<<dp[m][t]<<endl;
    }

    return 0;
}
