
#include<iostream>
using namespace std;
int max_num(int a,int b)
{
    return a>b?a:b;
}
int dp[1001];//��i����Ʒ��j������е�����ֵ
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
            dp[i]=0;
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=t; j>=buf[i].ti; j--)
            {
                dp[j]= max_num(dp[j],dp[j-buf[i].ti]+buf[i].val);
                //�õ���ķ��������ڲ��ı�ǰ���i-1��ǰ���¶����ڵ�״̬���в���������ʡȥ����ѭ��j<buf[i].ti�Ĳ���
            }

        }
        cout<<dp[t]<<endl;
    }

    return 0;
}
