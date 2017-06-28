#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int n,a;//input numbers; the integer which need to be added into stack

    char c;
    while(cin>>n)
    {
        stack<int>s;
        for(int i=0;i<n;i++)
        {
            cin>>c;
            if(c=='P')
            {
                cin>>a;
                s.push(a);
            }
            else if(c=='O')
            {
                if(s.empty())
                    continue;
                else
                    s.pop();
            }
            else
            {
                if(s.empty())
                    cout<<"E"<<endl;
                else
                    cout<<s.top()<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
