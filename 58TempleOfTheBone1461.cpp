
#include<iostream>
using namespace std;
bool success;
int n,m,t;
char maze[7][7];
int go[][2]={
    -1,0,
    1,0,
    0,1,
    0,-1
};

void DFS(int a,int b,int time)
{
    for(int i=0;i<4;i++)
    {
        int nx=a+go[i][0];
        int ny=b+go[i][1];
        if(nx<1||nx>n||ny<1||ny>m) continue;//超出迷宫范围
        if(maze[nx][ny]=='X') continue;//遇到墙
        if(maze[nx][ny]=='D')
        {
            if(time+1==t)
            {
                success=true;
                return ;
            }
            else
                continue;
        }
        cout<<nx<<" "<<ny<<" "<<time<<endl;
        maze[nx][ny]='X';

        DFS(nx,ny,time+1);

        maze[nx][ny]='.';//因为是深度递归，所以回到上一个节点遍历他的其他子树的时候需要把走过的点改回来
        if(success)   return ;//没有这一句运行的时候也不会出错。但是遍历的状态会增加。就是出的路可能不止一条，加success就是有一个就跳出
    }


}
int main()
{

    while(cin>>n>>m>>t)
    {
        if(n==0&&m==0&&t==0) break;
        for(int i=1;i<=n;i++)
            cin>>maze[i]+1;
        success=false;
        int na,nb;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                if(maze[i][j]=='D')
                {
                    na=i;
                    nb=j;
                    }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++)
            {
                if(maze[i][j]=='S'&&(i+j)%2==((na+nb)%2+t%2)%2)//只有在始末坐标上满足一定条件的才有进行筛选的资格
                {
                    maze[i][j]='X';
                    DFS(i,j,0);
                }
            }
        }
    if(success)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }

     return 0;
}
