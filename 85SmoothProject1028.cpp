#include<iostream>
#include<algorithm>
using namespace std;
struct E
{
    int a;//start
    int b;//end
    int c;//cost
    int s;//״̬1/0
    bool operator <(const E &e)const
    {
        return c<e.c;
    }

} edge[6000];//����Ϊn*(n-1)/2,�Ƚڵ�����ܶ��أ�����critical��

int Tree[110];
int FindRoot(int x)
{
    if(Tree[x]==-1)
        return x;
    else
    {
        int tmp=FindRoot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}

int main()
{
    int N;
    while(cin>>N&&N!=0)
    {
        int num=N*(N-1)/2;
        for(int i=1; i<=N; i++)
            Tree[i]=-1;//initiate
        for(int i=1; i<=num; i++)
        {
            cin>>edge[i].a>>edge[i].b>>edge[i].c>>edge[i].s;
            if(edge[i].s==1)
                edge[i].c=0;//���ǲ����ټ�һ���ˣ������Ĳ��軹��һ������
        }
        sort(edge+1,edge+1+num);
        int ans=0;
        for(int i=1; i<=num; i++)
        {

            int a=FindRoot(edge[i].a);
            int b=FindRoot(edge[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=edge[i].c;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
