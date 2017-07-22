#include<iostream>
#include<queue>
using namespace std;
bool mark[101][101][101];

struct state{
    int a,b,c;
    int t;
};
queue<state> q;
void aTob(int &a,int sa,int &b,int sb)//a，b:两个杯子中液体容积，sa，sb：两个容器的体积
{
    if(sb-b>=a)
    {
        b+=a;
        a=0;
    }
    else
    {
        a=a-(sb-b);//因为这里面操作sb和b了 所以要把b的赋值放在下面
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
        aTob(a,s,b,n);//从a倒入b
        if(mark[a][b][c]==false)//if语句的判断非常的重要，一定要看清楚是不是写了两个等于号
        {
            mark[a][b][c]=true;
            //因为有几个if语句需要原来的a，b，c，所以这里需要有临时变量把他保存下来
            state tm;
            tm.a=a;
            tm.b=b;
            tm.c=c;
            tm.t=now.t+1;
           // cout<<a<<" "<<b<<" "<<c<<endl;
            if(a==s/2&&b==s/2) return tm.t;//如果达到了平分的标准
            if(a==s/2&&c==s/2) return tm.t;
            if(b==s/2&&c==s/2) return tm.t;
            q.push(tm);
        }

        a=now.a;
        b=now.b;
        c=now.c;
        aTob(b,n,a,s);//从b倒入a
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
        aTob(a,s,c,m);//从a倒入c
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
        aTob(c,m,a,s);//从c倒入a
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
        aTob(b,n,c,m);//从b倒入c
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
        aTob(c,m,b,n);//从b倒入c
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
        if(s%2==1)//如果原始的可乐体积是奇数的话，肯定不能平分
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
        q.push(tmp);//每次push的时候都要改变mark
        mark[s][0][0]=true;
        int ret=BFS(s,n,m);//传参数的时候要特别注意
        //cout<<"ret"<<ret<<endl;
        if(ret>0)
            cout<<ret<<endl;
        else
            cout<<"NO"<<endl;
    }
     return 0;
}

