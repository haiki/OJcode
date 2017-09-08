#include<iostream>
#include<queue>//虽然是队列，但是意思是堆，和栈的有点一样，而不和队列一样
using namespace std;

int main()
{
    int n;
    priority_queue<int, vector<int>, greater<int> > q;
    while(cin>>n&&n!=0)
    {
        while(!q.empty()) q.pop();//这句话非常的重要，因为有多组数据。而每组数据最后都必然有一个数在堆中，所以要弹出
        int fruit[n];
        for(int i=0;i<n;i++)
           {
               cin>>fruit[i];
               q.push(fruit[i]);
           }
        //sort(fruit,fruit+n);不能用sort这么简单，因为需要动态的变化
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
