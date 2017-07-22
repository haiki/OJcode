
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
        if(nx<1||nx>n||ny<1||ny>m) continue;//�����Թ���Χ
        if(maze[nx][ny]=='X') continue;//����ǽ
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

        maze[nx][ny]='.';//��Ϊ����ȵݹ飬���Իص���һ���ڵ������������������ʱ����Ҫ���߹��ĵ�Ļ���
        if(success)   return ;//û����һ�����е�ʱ��Ҳ����������Ǳ�����״̬�����ӡ����ǳ���·���ܲ�ֹһ������success������һ��������
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
                if(maze[i][j]=='S'&&(i+j)%2==((na+nb)%2+t%2)%2)//ֻ����ʼĩ����������һ�������Ĳ��н���ɸѡ���ʸ�
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
