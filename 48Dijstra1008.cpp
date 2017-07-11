#include<iostream>
#include<vector>
using namespace std;
//相当于每个起始节点
struct Edge
{
    int next;
    int c;// the lowest path
    int cost;//expend
};

vector<Edge>edge[1001];
int dis[1001];//每个节点到源节点的距离向量
bool mark[1001];//每个节点是否已经找到了最短路径，是的话就设置为true
int cost[1001]= {0};
int main()
{
    int n,m;//节点个数和边数
    int s,t;//起点和终点
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(int i=1; i<=n; i++)
            edge[i].clear();//首先把每个链表的头清空
        for(int j=0; j<m; j++)
        {
            int a,b,d,p;

            cin>>a>>b>>d>>p;
            Edge tmp;
            tmp.c=d;
            tmp.cost=p;
            tmp.next=b;
            edge[a].push_back(tmp);//添加链表的时候需要把这两个点都添加一次
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        cin>>s>>t;
        //初始化每一个节点的距离以及是否加入k集合
        for(int i=1; i<=n; i++)
        {
            dis[i]=-1;
            mark[i]=false;
        }
        //开始Dijstra
        dis[s]=0;
        mark[s]=0;
        int newp=s;//每一轮循环后能够加入k集合的新节点
        for(int i=1; i<=n; i++) //有n条链表，每个节点为头就有一条
        {
            for(int j=0; j<edge[newp].size(); j++) //vector中有几条与这个节点相互联系的节点
            {
                int t=edge[newp][j].next;
                int pa=edge[newp][j].c;//一个点到另一个点的距离，不一定是原点
                int co=edge[newp][j].cost;
                if(mark[t]==true)   continue;
                if(dis[t]==-1||dis[t]>pa+dis[newp]||dis[t]==pa+dis[newp]&&cost[t]>cost[newp]+co)
                {
                    dis[t]=pa+dis[newp];
                    cost[t]=cost[newp]+co;
                }
            }
            int sum=123456778;//求这些距离中的最短,得出一个新的可以加入k的节点
            for(int i=1; i<=n; i++) //比较已经重新建立的最短路径，在这些点中选出最小的那个点加入k
            {
                if(mark[i]==true) continue;
                if(dis[i]==-1) continue;
                if(dis[i]<sum)
                {
                    sum=dis[i];
                    newp=i;
                }
            }
            mark[newp]=true;
        }
        cout<<dis[t]<<" "<<cost[t]<<endl;

    }
    return 0;
}

