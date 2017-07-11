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
            int tmp=tree[x];//����Ҫ����������������x=tree[x]�Ѿ��Ǹ��� �Ͳ�����ѭ����
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
    double x,y;//���������
    double getDistance(Point a)
    {
        double d=(x-a.x)*(x-a.x)+(y-a.y)*(y-a.y);//��ʽ�㶼�ǲ�ס  �㻹�۸�ɶ��
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

    int siz=0;//����
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
        sort(edge,edge+siz);//��Ϊsiz�Ǵ�0��ʼ�ģ�����edge����Ҫ��1
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
