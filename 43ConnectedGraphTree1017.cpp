#include<iostream>
#include<algorithm>
using namespace std;
#define N 100
int tree[N];
int FindRoot(int x)
{
    if(tree[x]==-1)
        return x;
    else
    {
        int tmp=FindRoot(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}
class Edge
{
public:
    int a,b;//һ���ߵ������ڵ�
    int cost;
    bool operator <(const Edge &e)const
    {
        return cost<e.cost;
    }

} edge[5000];
int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        for(int i=1; i<=n; i++)
            tree[i]=-1;
        int s=n*(n-1)/2;//n���ڵ�ı�����Ҫ��ס �����Ŀ����
        for(int k=0; k<s; k++)
        {
            cin>>edge[k].a>>edge[k].b>>edge[k].cost;
        }
        sort(edge,edge+s);
        int ans=0;//���·����ʼΪ0��
        for(int j=0; j<s; j++)
        {
            int a=FindRoot(edge[j].a);
            int b=FindRoot(edge[j].b);
            if(a!=b)//��仰��ʵ�����ڱ����ظ������ˣ�����ѭ��������ÿһ���߶�Ҫ����һ��
            {
                tree[a]=b;
                ans+=edge[j].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
