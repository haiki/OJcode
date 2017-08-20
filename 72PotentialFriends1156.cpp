#include<iostream>
using namespace std;
//想到了，没有更好的方法去优化，那么就是去试一试，不要苦恼！数据很少，两层循环也不会有很大的时间复杂度
int Hash[201];
int main()
{
    int n,m;
    int res[201];//用来统计每个人的潜在朋友
    while(cin>>n>>m)
    {
        for(int i=1; i<=n; i++)
        {
            res[i]=0;//初始化
            cin>>Hash[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(Hash[i]==Hash[j])
                   {
                       res[i]++;
                   }
            }
            res[i]-=1;//因为每次一都把自己又算了一遍
        }
        for(int i=1;i<=n;i++)
        {
            if(res[i]>0)
                cout<<res[i]<<endl;
            else
                cout<<"BeiJu"<<endl;
        }
        }
    return 0;

}
