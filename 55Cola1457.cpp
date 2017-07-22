#include<iostream>
#include<queue>
using namespace std;
bool mark[101][101][101];

struct state{
    int a,b,c;
    int t;
};
queue<state> q;
void aTob(int &a,int sa,int &b,int sb)//a��b:����������Һ���ݻ���sa��sb���������������
{
    if(sb-b>=a)
    {
        b+=a;
        a=0;
    }
    else
    {
        a=a-(sb-b);//��Ϊ���������sb��b�� ����Ҫ��b�ĸ�ֵ��������
        b=sb;

    }
}
int BFS(int s,int n,int m)
{
    while(!q.empty())
    {
        state now=q.front();
        q.pop();
        int a,b,c;
        a=now.a;
        b=now.b;
        c=now.c;
        aTob(a,s,b,n);//��a����b
        if(mark[a][b][c]==false)//if�����жϷǳ�����Ҫ��һ��Ҫ������ǲ���д���������ں�
        {
            mark[a][b][c]=true;
            //��Ϊ�м���if�����Ҫԭ����a��b��c������������Ҫ����ʱ����������������
            state tm;
            tm.a=a;
            tm.b=b;
            tm.c=c;
            tm.t=now.t+1;
           // cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==s/2&&b==s/2) return tm.t;//����ﵽ��ƽ�ֵı�׼
            if(a==s/2&&c==s/2) return tm.t;
            if(b==s/2&&c==s/2) return tm.t;
            q.push(tm);
        }

        a=now.a;
        b=now.b;
        c=now.c;
        aTob(b,n,a,s);//��b����a
        if(mark[a][b][c]==false)
        {
            mark[a][b][c]=true;
            state tm;
            tm.a=a;
            tm.b=b;
            tm.c=c;
            tm.t=now.t+1;
             //cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==s/2&&b==s/2) return tm.t;
            if(a==s/2&&c==s/2) return tm.t;
            if(b==s/2&&c==s/2) return tm.t;
            q.push(tm);
        }

        a=now.a;
        b=now.b;
        c=now.c;
        aTob(a,s,c,m);//��a����c
        if(mark[a][b][c]==false)
        {
            mark[a][b][c]=true;
            state tm;
            tm.a=a;
            tm.b=b;
            tm.c=c;
            tm.t=now.t+1;
            // cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==s/2&&b==s/2) return tm.t;
            if(a==s/2&&c==s/2) return tm.t;
            if(b==s/2&&c==s/2) return tm.t;
            q.push(tm);
        }

        a=now.a;
        b=now.b;
        c=now.c;
        aTob(c,m,a,s);//��c����a
        if(mark[a][b][c]==false)
        {
            mark[a][b][c]=true;
            state tm;
            tm.a=a;
            tm.b=b;
            tm.c=c;
            tm.t=now.t+1;
            // cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==s/2&&b==s/2) return tm.t;
            if(a==s/2&&c==s/2) return tm.t;
            if(b==s/2&&c==s/2) return tm.t;
            q.push(tm);
        }

        a=now.a;
        b=now.b;
        c=now.c;
        aTob(b,n,c,m);//��b����c
        if(mark[a][b][c]==false)
        {
            mark[a][b][c]=true;
            state tm;
            tm.a=a;
            tm.b=b;
            tm.c=c;
            tm.t=now.t+1;
            // cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==s/2&&b==s/2) return tm.t;
            if(a==s/2&&c==s/2) return tm.t;
            if(b==s/2&&c==s/2) return tm.t;
            q.push(tm);
        }

        a=now.a;
        b=now.b;
        c=now.c;
        aTob(c,m,b,n);//��b����c
        if(mark[a][b][c]==false)
        {
            mark[a][b][c]=true;
            state tm;
            tm.a=a;
            tm.b=b;
            tm.c=c;
            tm.t=now.t+1;
            // cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==s/2&&b==s/2) return tm.t;
            if(a==s/2&&c==s/2) return tm.t;
            if(b==s/2&&c==s/2) return tm.t;
            q.push(tm);
        }


    }
    return -1;
}

int main()
{
    int s,n,m;
    while(cin>>s>>n>>m)
    {
        if(s==0&&n==0&&m==0)
            break;
        if(s%2==1)//���ԭʼ�Ŀ�������������Ļ����϶�����ƽ��
        {
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=0;i<=s;i++){
                for(int j=0;j<=n;j++){
                    for(int k=0;k<=m;k++){
                        mark[i][j][k]=false;}
                }
        }

        state tmp;
        tmp.a=s;
        tmp.b=0;
        tmp.c=0;
        tmp.t=0;
        if(!q.empty()) q.pop();
        q.push(tmp);//ÿ��push��ʱ��Ҫ�ı�mark
        mark[s][0][0]=true;
        int ret=BFS(s,n,m);//��������ʱ��Ҫ�ر�ע��
        //cout<<"ret"<<ret<<endl;
        if(ret>0)
            cout<<ret<<endl;
        else
            cout<<"NO"<<endl;
    }
     return 0;
}

