#include<iostream>
using namespace std;
#define OFFSET 500000
int Hash[1000001];
int main()
{
    int n,m;
    for(int i=-500000;i<=500000;i++)
    {
        Hash[i+OFFSET]=0;
    }
    while(cin>>n&&n>0&&n<1000000)
    {
        cin>>m;
        int num=0;
        for(int j=0;j<n;j++)
        {
            cin>>num;
            Hash[num+OFFSET]=1;
        }
        for(int k=500000;k>=-500000&&m!=0;k--)
        {
            if(Hash[k+OFFSET]==1)
                {
                    cout<<k<<" ";
                    m--;
                }
            if(m==0)
                cout<<endl;
        }
    }
return 0;

}
