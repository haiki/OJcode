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
//�ǵݹ�ʵ��
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
        for(int i=1; i<=n; i++) //�տ�ʼÿ�������ǹ����Ľڵ㣬��1-n���
            tree[i]=-1;
        int a,b;
        for(int i=0; i<m; i++)
        {
            cin>>a>>b;
            a=FindRoot(a);
            b=FindRoot(b);
            if(a!=b)
            {
                tree[a]=b;//��������ڵ㲻��һ��������  ���һ���ĸ��ڵ�����Ϊ��һ��Ԫ�� ���ϲ���������
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
