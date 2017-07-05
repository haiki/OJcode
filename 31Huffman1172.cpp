#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int> >q;
    int n;
    while(cin>>n&&n>=2&&n<=1000)
    {
        while(q.empty()==false)//critical
            q.pop();
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            q.push(x);
        }
        int ans=0;//统计权值与节点的值的乘积和
        while(q.size()>1)
        {
            int a=q.top();
            q.pop();
            int b=q.top();
            q.pop();
            ans+=a+b;
            q.push(a+b);//critical
        }
        cout<<ans<<endl;
    }
    return 0;
}
