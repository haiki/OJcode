#include<iostream>
using namespace std;
#define OFFSET 500000
int Hash[1000001];
int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        for(int i=-500000; i<=500000; i++)//这个一定要放在while里面，否则多次排序的时候就重复存放了
        {
            Hash[i+OFFSET]=0;
        }

        for(int j=1; j<=n; j++)//注意边界取值，j<=n
        {
            int num;
            cin>>num;
            Hash[num+OFFSET]=1;
        }
        bool flag=false;
        for(int k=500000; k>=-500000&&m!=0; k--)
        {
            if(Hash[k+OFFSET]==1)
            {
                if(flag==false)
                    {
                        flag=true;
                        cout<<k;
                        m--;//为什么不可以把m的变化放在for循环？有可能是逗号的优先级使得循环没有终止
                    }
                else{
                    cout<<" "<<k;
                    m--;
                }
                /*cout<<k;
                m--;
                if(m!=0)
                    cout<<" ";
                else
                {
                    cout<<endl;
                    break;
                }*/
            }
        }
    }
    return 0;

}
