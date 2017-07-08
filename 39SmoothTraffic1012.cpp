#include<iostream>
using namespace std;
#define N 1000
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
//非递归实现
/*int FindRoot(int x)
{
    if(tree[x]==-1)
        return x;
    else
    {
        int tmp=x;
        while(tree[x]!=-1)
        {
            x=tree[x];
        }
        int ret=x;
        x=tmp;
        while(tree[x]!=-1)
        {
            tree[x]=ret;
            x=tree[x];
        }
        return ret;
    }
}*/

int main()
{
    int n,m;
    while(cin>>n&&n!=0)
    {
        cin>>m;
        for(int i=1; i<=n; i++) //刚开始每个城镇都是孤立的节点，从1-n编号
            tree[i]=-1;
        int a,b;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            a=FindRoot(a);
            b=FindRoot(b);
            if(a!=b)
            {
                tree[a]=b;//如果两个节点不在一个集合中  则把一个的根节点设置为另一个元素 即合并两个集合
            }
        }
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(tree[i]==-1)
                ans++;
        }
        cout<<ans-1<<endl;
    }
    return 0;
}
