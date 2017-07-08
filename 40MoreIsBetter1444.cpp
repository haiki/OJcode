#include<iostream>
using namespace std;
#define N 10000001
int sum[N];
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
int main()
{
    int n;
    while(cin>>n)
    {
        for(int j=1;j<=N;j++)
        {
            tree[j]=-1;//刚开始都是独立的节点
            sum[j]=1;//每一个集合中的节点个数都是1
        }
        int a,b;
        for(int i=0;i<n;i++)
        {
            cin>>a>>b;
            a=FindRoot(a);
            b=FindRoot(b);
            if(a!=b)
            {
                tree[a]=b;
                sum[b]+=sum[a];//把a中的元素个数也加进来 很关键，整个题的核心语句
            }
        }
        int ans=1;//至少是有一个
        for(int i=1;i<=N;i++)
        {
            if(tree[i]==-1&&sum[i]>ans)
                ans=sum[i];
        }
        cout<<ans<<endl;
    }
}
