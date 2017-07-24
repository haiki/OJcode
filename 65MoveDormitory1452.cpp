#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x7fffffff//�������������� int����Ϊ��һλ�Ƿ���λ��0 ��ʾ����������

int dp[1001][2001];//��ʾ��j����Ʒ��ƥ���ǰi�ԡ���һά��i���ڶ�ά��j
int weight[2001];//ÿ������������
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF )//while(cin>>n>>k)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&weight[i]);//cin>>weight[i];
        }
        sort(weight+1,weight+n+1);
        for(int i=1; i<=n; i++)//��Ϊweeight������֮��˳��仯�ˣ����԰ѳ�ʼ����������ĺ���ȽϺ�
        {
            dp[0][i]=0;//��ʼ��������0�Ե�ʱ�����0���������Ը�������ṩ��ʼֵ
        }
        for(int i=1; i<=k; i++)
        {
            for(int j=2*i; j<=n; j++)
            {
                int tmp=dp[i-1][j-2]+(weight[j]-weight[j-1])*(weight[j]-weight[j-1]);
                //������������Գɹ��ˣ�����ǰ��ļ��Ϲ�ʽ
                if(j==2*i)
                    dp[i][j]=INF;
                else
                    dp[i][j]=dp[i][j-1];
                if(tmp<dp[i][j])
                    dp[i][j]=tmp;
            }
        }
        printf("%d\n",dp[k][n]);//cout<<dp[k][n]<<endl
    }
    return 0;
}
