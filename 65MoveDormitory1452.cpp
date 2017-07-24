#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF 0x7fffffff//这是最大的整型数 int（因为第一位是符号位，0 表示他是正数）

int dp[1001][2001];//表示在j件物品中匹配的前i对。第一维是i，第二维是j
int weight[2001];//每个包裹的重量
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
        for(int i=1; i<=n; i++)//因为weeight在排序之后顺序变化了，所以把初始化放在这个的后面比较好
        {
            dp[0][i]=0;//初始化，当有0对的时候就是0，这样可以给后面的提供初始值
        }
        for(int i=1; i<=k; i++)
        {
            for(int j=2*i; j<=n; j++)
            {
                int tmp=dp[i-1][j-2]+(weight[j]-weight[j-1])*(weight[j]-weight[j-1]);
                //如果最后两个配对成功了，就用前面的加上公式
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
