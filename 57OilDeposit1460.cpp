#include<iostream>
using namespace std;
char atlas[101][101];
bool mark[101][101];
 int n,m;
int go[8][2]=
{
    -1,0,
    1,0,
    0,-1,
    0,1,
    1,1,
    1,-1,
    -1,1,
    -1,-1
};
void DFS(int a,int b)
{
    for(int i=0; i<8; i++)
    {
        int nx=a+go[i][0];//下标从0开始
        int ny=b+go[i][1];
        if(nx<1||nx>n||ny<1||ny>m)//少了就会运行出bug
            continue;
        if(mark[nx][ny]==true)
            continue;
        if(atlas[nx][ny]=='*')
            continue;
        mark[nx][ny]=true;
        DFS(nx,ny);
    }
    return ;//递归完需要有返回

}
int main()
{

    while(cin>>n>>m)
    {
        if(n==0&&m==0)
            break;
        for(int i=1; i<=n; i++)//一次输入一行，和下面的一个一个字符的输入等价
        {
            cin>>atlas[i]+1;
        }


        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                //cin>>atlas[i][j];
                mark[i][j]=false;
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(atlas[i][j]=='*')
                    continue;
                if(mark[i][j]==true)
                    continue;
                DFS(i,j);
                ans++;
            }
        }
        cout<<ans<<endl;

    }
    return 0;
}

