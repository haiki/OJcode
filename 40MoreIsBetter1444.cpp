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
            tree[j]=-1;//�տ�ʼ���Ƕ����Ľڵ�
            sum[j]=1;//ÿһ�������еĽڵ��������1
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
                sum[b]+=sum[a];//��a�е�Ԫ�ظ���Ҳ�ӽ��� �ܹؼ���������ĺ������
            }
        }
        int ans=1;//��������һ��
        for(int i=1;i<=N;i++)
        {
            if(tree[i]==-1&&sum[i]>ans)
                ans=sum[i];
        }
        cout<<ans<<endl;
    }
}
