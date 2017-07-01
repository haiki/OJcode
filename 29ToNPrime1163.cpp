#include<iostream>
using namespace std;
#define N 10000
bool mark[N+1];
int prime_size=0;
int is_prime[N];
void init()
{
    for(int i=0;i<=N;i++)
        mark[i]=false;
    for(int j=2;j<=N;j++)
    {
        if(mark[j]==true)
            continue;
        else
        {
            is_prime[prime_size++]=j;
            for(int k=j*j;k<=N;k+=j)
            {
                mark[k]=true;
            }

        }
    }
}
int main()
{
    init();
    int n;
    while(cin>>n)
    {
        bool flag = false;
        for(int i=0;i<prime_size;i++)
        {
            if(is_prime[i]<n&&is_prime[i]%10==1)
            {
                if(flag==true)
                    cout<<" "<<is_prime[i];
                else
                {
                    flag=true;
                    cout<<is_prime[i];
                }
            }
        }
        if(flag==false)
            cout<<"-1";
        cout<<endl;
    }
    return 0;

}
