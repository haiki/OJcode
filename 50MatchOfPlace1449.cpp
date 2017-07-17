#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>edge[501];
priority_queue< int,vector<int>,greater<int> > q;
//��Ϊ��ĿҪ���ж�����������ʱ��С��Ҫ��ǰ�����������ʹ���˴�С������������ȶ��У�
//����ÿ�μ����µĶ�Ϊ0�Ľڵ��ʱ��ͻ��ź���С�������
int main()
{

    int indegree[501];
    int n,m;
    while(cin>>n>>m)
    {

        for(int i=1; i<=n; i++)
        {
            edge[i].clear();
            indegree[i]=0;
        }
        while(m--)
        {
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);
            indegree[b]++;
        }
        while(!q.empty())
            q.pop();
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        bool flag=true;
        while(!q.empty())
        {
            int newp=q.top();
            if(flag)
            {
                cout<<newp;
                flag=false;
            }
            else
            {
                cout<<" "<<newp;
            }
            q.pop();

            for(int j=0; j<edge[newp].size(); j++)
            {
                indegree[edge[newp][j]]--;
                if(indegree[edge[newp][j]]==0)
                    q.push(edge[newp][j]);
            }
        }
cout<<endl;

    }
    return 0;
}
