#include<iostream>
using namespace std;
//ʹ���ڽӾ���,�ڵ��֮�����̾���
int ans[101][101];//����
int main()
{
    int n,m;//n:node; m:the sum of rode
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                ans[i][j]=-1;//infinite
            ans[i][i]=0;//�Խ��߳�ʼ��Ϊ0
        }
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ans[a][b]=ans[b][a]=c;//����ͼ������Ҫ��������
    }
   // floyd�ı���
    for(int k=1;k<=n;k++)//�м�ڵ�Ϊ1��2��3��4������ʱ���ڽӾ���
    {
        for(int i=1;i<=n;i++)//�жϽڵ�֮����ֱ�������Ƚ϶̻��Ǿ���ĳһ��ֵ��ʱ��·���Ƚ϶�
            for(int j=1;j<=n;j++)
        {
            if(ans[i][k]==-1||ans[k][j]==-1)continue;
            if(ans[i][j]==-1||ans[i][k]+ans[k][j]<ans[i][j])
            {
                ans[i][j]=ans[i][k]+ans[k][j];
            }
        }
    }
    cout<<ans[1][n]<<endl;
    }
    return 0;
}
