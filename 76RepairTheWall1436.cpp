#include<iostream>
#include<algorithm>
using namespace std;
//很简单的东西不要被他的长篇大论吓坏了
bool cmp(int a,int b)//用来制定排序规则为由大到小
{
    return a>b;
}
int main()
{
    int L,N;
    while(cin>>L>>N)
    {
        int buf[610];
        int ans=0;//用来记录需要多少个block
        for(int i=0;i<N;i++)
        {
            cin>>buf[i];
        }
        sort(buf,buf+N,cmp);
        int j;
        for(j=0;j<N;j++)
        {
            L-=buf[j];
            ans++;
            if(L<=0)
                break;
        }
        if(j==N)//不可以是ans，因为有可能N=1
            cout<<"impossible"<<endl;
        else
            cout<<ans<<endl;

    }
    return 0;
}

