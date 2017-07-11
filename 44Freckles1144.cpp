#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
#define N 101
//#define M N*(N-1)/2
int tree[N];
int FindRoot(int x)
{
    if(tree[x]==-1)
        return x;
    else
    {
        int t=x;
        while(tree[x]!=-1)
        {
           x=tree[x];
        }
        int ret=x;
        x=t;
        while(tree[x]!=-1)
        {
            int tmp=tree[x];//必须要这样交换，否则你x=tree[x]已经是根了 就不会再循环了
            tree[x]=ret;
            x=tmp;
        }
        return ret;
    }
}
class Edge{
public:

    int a,b;
    double cost;
    bool operator <(const Edge& e)const
        {return cost<e.cost;}

}edge[5000];

class Point{
    public:
    double x,y;//两点的坐标
    double getDistance(Point a)
    {
        double d=(x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);//公式你都记不住  你还嫩干啥！
        return sqrt(d);
    }
}p[N];

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            tree[i]=-1;
        for(int j=1;j<=n;j++)
        {
            cin>>p[j].x>>p[j].y;
        }

    int siz=0;//边数
        for(int k=1;k<=n;k++)
        {
            for(int j=k+1;j<=n;j++)
            {
                edge[siz].a=k;
                edge[siz].b=j;
                edge[siz].cost=p[k].getDistance(p[j]);
                siz++;
            }
        }
        sort(edge,edge+siz);//因为siz是从0开始的，所以edge不需要加1
        double ans=0.0;
        for(int i=0;i<siz;i++)
        {
            int a=FindRoot(edge[i].a);
            int b=FindRoot(edge[i].b);
            if(a!=b)
            {
                tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        cout<<fixed<<setprecision(2)<<ans<<endl;
    }
    return 0;
}
