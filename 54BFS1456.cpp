#include<iostream>
#include<queue>
using namespace std;
//�����Ŀһ�����ж����������������ӳ����ѭ������д��  Ȼ���һֱwrong��Ȼ���������while��cin>>n����Ҳ��һ�δ�����
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
            int nx=tmp.a+go[i][0];//Ų��һ��������ĵ�
            int ny=tmp.b+go[i][1];
            int nz=tmp.c+go[i][2];
            int tt=tmp.t+1;
            if(nx<0 || nx>=a || ny<0 || ny>=b || nz<0 || nz>=c) continue;//����ߵ����Թ�������������
            if(mark[nx][ny][nz]==true) continue;//����Ѿ������״̬������
            if(sta[nx][ny][nz]==1) continue;//�����ǽ����Ҳ����


            state news;
            news.a=nx;
            news.b=ny;
            news.c=nz;
            news.t=tt;

            mark[nx][ny][nz]=true;
            q.push(news);

            if( nx == a-1 && ny == b-1 && nz == c-1)//��д����һ��������������1��Сʱ�Ĵ�������
                {
                return news.t;
            }//����Ѿ��ߵ����Ǹ����ڵĵ�
        }
    }
    return -1;//�ж�����������˼

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
