#include<iostream>
using namespace std;
//使用邻接矩阵,节点对之间的最短距离
int ans[101][101];//距离
int main()
{
    int n,m;//n:node; m:the sum of rode
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                ans[i][j]=-1;//infinite
            ans[i][i]=0;//对角线初始化为0
        }
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        ans[a][b]=ans[b][a]=c;//无向图所以需要保存两个
    }
   // floyd的本质
    for(int k=1;k<=n;k++)//中间节点为1、2、3、4。。。时的邻接矩阵
    {
        for(int i=1;i<=n;i++)//判断节点之间是直接相连比较短还是经过某一个值的时候路径比较短
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
