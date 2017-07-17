#include<iostream>
#include<queue>
using namespace std;
//不知为何要设置成main函数外面的
vector<int>edge[101];//存放与当前节点相连接的下一个节点的信息,节点号  为整数。邻接矩阵
queue<int>q;//存放入度为1的节点号  可以不是queue
int main()
{
    int indegree[101];//存放每个节点的入度

    int n,m;//n：node  m：edge
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        for(int i=0; i<n; i++)
        {
            indegree[i]=0;
            edge[i].clear();//邻接矩阵的初始化
        }
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);//与a相邻的边 ， 因为是有向图，所以存储一遍就好
            indegree[b]++;
        }
        while(!q.empty()) q.pop();//弹元素出因为上一轮没有弹出的   这个一般自己想不到  ！！！
        //将入度为0 的点加入
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;//每次有一个可以确定拓扑序列的节点就加一
        while(!q.empty())
        {
            int newp=q.front();
            q.pop();
            cnt++;  //cout<<cnt<<endl;
            for(int j=0; j<edge[newp].size(); j++)
            {
                indegree[edge[newp][j]]--;//不能换成另一个变量，只能是这个数组自身的值变化
                //删除与拓扑序列中的节点相连的节点的那个度
                if(indegree[edge[newp][j]]==0)
                {
                    q.push(edge[newp][j]);
                }

            }
        }
        if(cnt==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;

}

