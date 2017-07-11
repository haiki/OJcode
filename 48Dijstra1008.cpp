#include<iostream>
#include<vector>
using namespace std;
//�൱��ÿ����ʼ�ڵ�
struct Edge
{
    int next;
    int c;// the lowest path
    int cost;//expend
};

vector<Edge>edge[1001];
int dis[1001];//ÿ���ڵ㵽Դ�ڵ�ľ�������
bool mark[1001];//ÿ���ڵ��Ƿ��Ѿ��ҵ������·�����ǵĻ�������Ϊtrue
int cost[1001]= {0};
int main()
{
    int n,m;//�ڵ�����ͱ���
    int s,t;//�����յ�
    while(cin>>n>>m&&n!=0&&m!=0)
    {
        for(int i=1; i<=n; i++)
            edge[i].clear();//���Ȱ�ÿ�������ͷ���
        for(int j=0; j<m; j++)
        {
            int a,b,d,p;

            cin>>a>>b>>d>>p;
            Edge tmp;
            tmp.c=d;
            tmp.cost=p;
            tmp.next=b;
            edge[a].push_back(tmp);//��������ʱ����Ҫ���������㶼���һ��
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        cin>>s>>t;
        //��ʼ��ÿһ���ڵ�ľ����Լ��Ƿ����k����
        for(int i=1; i<=n; i++)
        {
            dis[i]=-1;
            mark[i]=false;
        }
        //��ʼDijstra
        dis[s]=0;
        mark[s]=0;
        int newp=s;//ÿһ��ѭ�����ܹ�����k���ϵ��½ڵ�
        for(int i=1; i<=n; i++) //��n������ÿ���ڵ�Ϊͷ����һ��
        {
            for(int j=0; j<edge[newp].size(); j++) //vector���м���������ڵ��໥��ϵ�Ľڵ�
            {
                int t=edge[newp][j].next;
                int pa=edge[newp][j].c;//һ���㵽��һ����ľ��룬��һ����ԭ��
                int co=edge[newp][j].cost;
                if(mark[t]==true)   continue;
                if(dis[t]==-1||dis[t]>pa+dis[newp]||dis[t]==pa+dis[newp]&&cost[t]>cost[newp]+co)
                {
                    dis[t]=pa+dis[newp];
                    cost[t]=cost[newp]+co;
                }
            }
            int sum=123456778;//����Щ�����е����,�ó�һ���µĿ��Լ���k�Ľڵ�
            for(int i=1; i<=n; i++) //�Ƚ��Ѿ����½��������·��������Щ����ѡ����С���Ǹ������k
            {
                if(mark[i]==true) continue;
                if(dis[i]==-1) continue;
                if(dis[i]<sum)
                {
                    sum=dis[i];
                    newp=i;
                }
            }
            mark[newp]=true;
        }
        cout<<dis[t]<<" "<<cost[t]<<endl;

    }
    return 0;
}

