#include<iostream>
#include<algorithm>
using  namespace std;
int tree[110];
//int sum[110];
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
class Edge{
public:
    int a,b;
    int cost;
    bool operator < (const Edge &a)const{
        return cost<a.cost;

    }
}edge[101];
int main()
{
    int n,m;//·������ׯ��
    while(cin>>n>>m&&n!=0)
    {

        for(int k=1;k<=m;k++)
        {
            tree[k]=-1;
            //sum[k]=1;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>edge[i].a>>edge[i].b>>edge[i].cost;
        }
        sort(edge+1,edge+n+1);//һ��Ҫ��1������������ʲô�ط���ʼ
        for(int i=1;i<=n;i++)
            cout<<edge[i].cost<<" "<<endl;
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            int a=FindRoot(edge[j].a);
            int b=FindRoot(edge[j].b);
            if(a!=b)
                {
                    tree[a]=b;
                    ans+=edge[j].cost;
                    //sum[b]+=sum[a];
                    //cout<<edge[j].a<<" "<<edge[j].b<<endl;
                }
        }
      /* int s=0;
        for(int i=1;i<=m;i++)
        {
            if(FindRoot(i)==i)
                s++;
        }
        if(s>1)
            cout<<"?"<<endl;
        else*/
            cout<<ans<<endl;
       //�൱�ڽ������ͨͼ�еĽڵ������һ��ͳ�ƣ�������Ƿ���ڸ����Ľڵ�������������������Ǹ�һ����
       /* int cou=1;
        for(int i=1;i<=m;i++)
        {
             if(tree[i]==-1&&sum[i]>cou)
                cou=sum[i];
        }
        if(cou!=m)
            cout<<"?"<<endl;
        else
            cout<<ans<<endl;*/

    }

    return 0;
}
