#include<iostream>
#include<vector>
using namespace std;

#define N 1001
//有时候题目要求的换行  就是你手动换行。。真是醉了！
int tree[N];
int sum[N];
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
    int T;
    while(cin>>T)
    {
        vector<int>v;
        vector<int>::iterator it;
        while(T--)
        {

            int n,m;
            cin>>n>>m;
            for(int i=1; i<=n; i++)
            {
                tree[i]=-1;
                sum[i]=1;
            }
            for(int j=0; j<m; j++)
            {
                int a,b;
                cin>>a>>b;
                a=FindRoot(a);
                b=FindRoot(b);
                if(a!=b)
                {
                    tree[a]=b;
                    sum[b]+=sum[a];
                }
            }
            int ans=0;
            for(int i=1; i<=n; i++)
            {
                if(tree[i]==-1)
                    ans++;
            }
            v.push_back(ans);

        }
        for(it=v.begin(); it!=v.end(); it++)
            cout<<*it<<endl;

    }
    return 0;
}
