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
        int cur=ful-emp;//������ʵ�����
        for(int i=0; i<=cur; i++)
        {
            dp[i]=INF;//��ΪҪ��װ�������Խ����˵�0��Ķ���ʼ��Ϊ������߲����ڣ���-1��
        }
        dp[0]=0;//���ݻ�Ϊ0ʱ��ֵҲΪ0
        for(int i=1; i<=n; i++)
        {
            for(int j=buf[i].wei; j<=cur; j++)//��ΪҪ����ǰ���Ѿ��ı��ֵ�����������ѭ����˳���
            {
                /*if(dp[j]>dp[j-buf[i].wei]+buf[i].val)
                    dp[j]=dp[j-buf[i].wei]+buf[i].val;*///����д����������
                if(dp[j-buf[i].wei]!=INF)//ֻ�������ſ�����ǰһ��״̬ת�Ƴ���ǰ״̬������ͱ���ԭ����ֵ����dp[i-1]һ��
                {
                    dp[j]=min_num(dp[j],dp[j-buf[i].wei]+buf[i].val);//ѡ���Ƚ�С���Ǹ�
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

