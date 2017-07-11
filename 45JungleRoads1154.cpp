#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
char tree[27];
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
    char a,b;//��ׯ�������Ǵ�д����ĸ
    int cost;
    bool operator <(const Edge &e)const
    {
        return cost<e.cost;
    }
} edge[20];

int main()
{
    int n;
    while(cin>>n&&n!=0)
    {
        for(int i=1; i<=n; i++)
        {
            tree[i]=-1;
        }
        int siz=0;//��¼�ж�������
        for(int i=0; i<n-1; i++)
        {
            char label;
            int num;
            cin>>label>>num;
            for(int j=0; j<num; j++)
            {
                edge[siz].a=label;//���һ�����໥�����ı߶�д����,��һ��˫��ѭ��
                cin>>edge[siz].b>>edge[siz].cost;
                siz++;
            }
        }
        sort(edge,edge+siz);
        int ans=0;
        for(int i=0; i<siz; i++)
        {
            int a=FindRoot(int(edge[i].a-64));
            int b=FindRoot(int(edge[i].b-64));
            if(a!=b)
            {
                tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
