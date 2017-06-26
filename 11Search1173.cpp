#include<iostream>
using namespace std;
int main()
{
    int Hash[101];
    int n,m;//n:arr.size;m:search arr.size;
    int x,y;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>x;
            Hash[x]=1;
        }
        cin>>m;
        for(int j=0;j<m;j++)
        {
            cin>>y;
            if(Hash[y]==1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }

    }
}
