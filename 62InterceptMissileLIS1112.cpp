#include<iostream>
#include<algorithm>
using namespace std;
int Missile[25];
int dp[25];

int main()
{
    int k;
    while(cin>>k){
    for(int i=0; i<k; i++)
    {
        cin>>Missile[i];
        dp[i]=1;
    }
    for(int i=0; i<k; i++)
    {
        int tmax=1;

        for(int j=0; j<i; j++)
        {
            if(Missile[i]<=Missile[j])
                {tmax=max(tmax,dp[j]+1);}
        }
        dp[i]=tmax;
    }
    int ans=0;
    for(int i=0;i<k;i++)
    {
       // cout<<dp[i]<<endl;
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;

}
return 0;
}
