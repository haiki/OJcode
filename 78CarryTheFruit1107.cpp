#include<iostream>
#include<queue>//��Ȼ�Ƕ��У�������˼�Ƕѣ���ջ���е�һ���������Ͷ���һ��
using namespace std;

int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int> > q;
    while(cin>>n&&n!=0)
    {
        while(!q.empty()) q.pop();//��仰�ǳ�����Ҫ����Ϊ�ж������ݡ���ÿ��������󶼱�Ȼ��һ�����ڶ��У�����Ҫ����
        int fruit[n];
        for(int i=0;i<n;i++)
           {
               cin>>fruit[i];
               q.push(fruit[i]);
           }
        //sort(fruit,fruit+n);������sort��ô�򵥣���Ϊ��Ҫ��̬�ı仯
        int ans=0;
        while(q.size()!=1)
        {
            int w1=q.top();
            q.pop();
            int w2=q.top();
            q.pop();
            q.push(w1+w2);
            ans+=w1+w2;
        }
        cout<<ans<<endl;
    }

    return 0;
}
