#include<iostream>
using namespace std;
#define N 1001
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
    int n,m;
    while(cin>>n>>m&&n!=0&m!=0)
    {
        for(int i=1;i<=n;i++)
        {
            tree[i]=-1;
        }
        int a,b;
        for(int j=0;j<m;j++)
        {
            cin>>a>>b;
            a=FindRoot(a);
            b=FindRoot(b);
            if(a!=b)
            {
                tree[a]=b;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(ans<3&&tree[i]==-1)
            {
                ans++;
            }
        }
        if(ans==1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
