#include<iostream>
#include<queue>
using namespace std;
//这个题目一定是有毒！！！先是跳出子程序的循环条件写错  然后就一直wrong，然后这个不是while（cin>>n），也出一次错！！！
bool mark[50][50][50];
bool sta[50][50][50];
struct state
{
    int a,b,c;
    int t;
};
queue<state>q;
int go[6][3]=
{
    -1,0,0,
    1,0,0,
    0,1,0,
    0,-1,0,
    0,0,1,
    0,0,-1
};
int BFS(int a,int b,int c)
{
    while(!q.empty())
    {
        state tmp=q.front();
        q.pop();
        for(int i=0; i<6; i++)
        {
            int nx=tmp.a+go[i][0];//挪动一步所到达的点
            int ny=tmp.b+go[i][1];
            int nz=tmp.c+go[i][2];
            int tt=tmp.t+1;
            if(nx<0 || nx>=a || ny<0 || ny>=b || nz<0 || nz>=c) continue;//如果走到了迷宫的外面则跳过
            if(mark[nx][ny][nz]==true) continue;//如果已经有这个状态则跳过
            if(sta[nx][ny][nz]==1) continue;//如果是墙，则也跳过


            state news;
            news.a=nx;
            news.b=ny;
            news.c=nz;
            news.t=tt;

            mark[nx][ny][nz]=true;
            q.push(news);

            if( nx == a-1 && ny == b-1 && nz == c-1)//就写错了一个变量导致找了1个小时的错！！！！
                {
                return news.t;
            }//如果已经走到了那个出口的点
        }
    }
    return -1;//中断这个程序的意思

}


int main()
{
    int n;
    cin>>n;

    int a,b,c,T;
    while(n--)
    {

        cin>>a>>b>>c>>T;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                for(int k=0; k<c; k++)
                {
                    cin>>sta[i][j][k];
                    mark[i][j][k]=false;
                }
            }
        }

        while(!q.empty()) q.pop();
        mark[0][0][0]=true;
        state st;
        st.a=st.b=st.c=st.t=0;
        q.push(st);
        int ret=BFS(a,b,c);
        if(ret<=T)
            cout<<ret<<endl;
        else
            cout<<"-1"<<endl;

    }
    return 0;


}
