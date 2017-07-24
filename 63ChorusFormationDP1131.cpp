#include<iostream>
using namespace std;
int max_num(int a,int b)
{
    return a>b?a:b;
}
int dp1[101],dp2[101],height[101];
int main()
{
    int n;
    while(cin>>n)
    {
        int i,j,tmax;

        for( i=1; i<=n; i++)
        {
            cin>>height[i];
            dp1[i]=1;
            dp2[i]=1;
        }
        for( i=1; i<=n; i++)
        {
            tmax=1;
            for( j=1; j<i; j++)
            {
                if(height[i]>height[j])
                {
                    tmax=max_num(tmax,dp1[j]+1);

                }
            }
            dp1[i]=tmax;
        }

        for(i=n; i>=1; i--)
        {
            tmax=1;
            for(j=n; j>i; j--)
            {
                if(height[i]>height[j])
                {
                    tmax=max_num(tmax,dp2[j]+1);
                }
            }
            dp2[i]=tmax;
        }
        int ans=1;

        for(i=1; i<=n; i++)
        {
            // cout<<dp1[i]<<" "<<dp2[i]<<endl;
            ans=max_num(ans,dp1[i]+dp2[i]-1);
        }
        ans=n-ans;
        cout<<ans<<endl;

    }
    return 0;

}

