#include<iostream>
#include<vector>
using namespace std;
//注意不要使用系统里面的关键字 ，这样在oj的时候很可能就错
struct Edge{
    int next;
    int cost;
};
vector<Edge>edge[601];
bool mark[601];
int tim[601];
int belong[601];//belong to which part
int main()
{
    int n,m;
    while(cin>>n>>m&&n!=0)
    {
        for(int i=1;i<=n;i++)
        {
            mark[i]=false;
            edge[i].clear();
            tim[i]=-1; //infinate
        }
        for(int i=0;i<m;i++)
        {
            int a,b,t;
            Edge tmp;
            cin>>a>>b>>t;
            tmp.cost=t;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);

        }
        for(int j=1;j<=n;j++)
        {
            cin>>belong[j];
        }
//实现在2-1的路时跳过，不予考虑！
           /* for(int i=1;i<=n;i++)
            {
                if(belong[i]==2)
                {
                    for(int j=0;j<edge[i].size();j++)
                    {
                        if(belong[edge[i][j].next]==1)
                            edge[i][j].cost=0;//weight=0
                    }
                }
            }
*/
            int newp=1;
            mark[1]=true;
            tim[1]=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<edge[newp].size();j++)
                {
                    int ne=edge[newp][j].next;
                    int ti=edge[newp][j].cost;
                    if(mark[ne]==true) continue;
                    if(ti==-1) continue;
                    //if(edge[newp][j].cost==0) continue;
                    if(belong[newp]==2&&belong[ne]==1)continue;
                    if(tim[ne]==-1||tim[ne]>tim[newp]+ti)
                    {
                        tim[ne]=tim[newp]+ti;
                    }
                }
                long  mi=344567;
                for(int k=1;k<=n;k++)
                {
                    if(tim[k]==-1||mark[k]==true)
                        continue;
                    if(tim[k]<mi)
                       {

                        mi=tim[k];
                        newp=k;
                       }
                }
                mark[newp]=true;

            }
            if(tim[2]==-1)
                cout<<"-1"<<endl;
            else
                cout<<tim[2]<<endl;
    }
    return 0;
}


