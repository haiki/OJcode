#include<iostream>
#include<queue>
using namespace std;
//��֪Ϊ��Ҫ���ó�main���������
vector<int>edge[101];//����뵱ǰ�ڵ������ӵ���һ���ڵ����Ϣ,�ڵ��  Ϊ�������ڽӾ���
queue<int>q;//������Ϊ1�Ľڵ��  ���Բ���queue
int main()
{
    int indegree[101];//���ÿ���ڵ�����

    int n,m;//n��node  m��edge
    while(cin>>n>>m)
    {
        if(n==0&&m==0) break;
        for(int i=0; i<n; i++)
        {
            indegree[i]=0;
            edge[i].clear();//�ڽӾ���ĳ�ʼ��
        }
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            edge[a].push_back(b);//��a���ڵı� �� ��Ϊ������ͼ�����Դ洢һ��ͺ�
            indegree[b]++;
        }
        while(!q.empty()) q.pop();//��Ԫ�س���Ϊ��һ��û�е�����   ���һ���Լ��벻��  ������
        //�����Ϊ0 �ĵ����
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;//ÿ����һ������ȷ���������еĽڵ�ͼ�һ
        while(!q.empty())
        {
            int newp=q.front();
            q.pop();
            cnt++;  //cout<<cnt<<endl;
            for(int j=0; j<edge[newp].size(); j++)
            {
                indegree[edge[newp][j]]--;//���ܻ�����һ��������ֻ����������������ֵ�仯
                //ɾ�������������еĽڵ������Ľڵ���Ǹ���
                if(indegree[edge[newp][j]]==0)
                {
                    q.push(edge[newp][j]);
                }

            }
        }
        if(cnt==n)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;

}

