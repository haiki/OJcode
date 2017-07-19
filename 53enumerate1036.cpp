
#include<iostream>
using namespace std;
//因为要取得最优值，所以从大到小的循环是一种快速而明智简洁的方法。
//break是跳出当前的循环，这一层循环
int main()
{
    int n;//turkey ’s number
    while(cin>>n)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int num=x*100+y*10+z;
        int i,j;
        bool flag=false;
        for(i=9; i>=1; i--)
        {
            for(j=9; j>=0; j--)
            {
                int sum=10000*i+10*num+j;
                if(sum%n==0)
                {
                    flag=true;
                    cout<<i<<" "<<j<<" "<<sum/n<<endl;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag==false)
            cout<<"0"<<endl;
    }
    return 0;

}

