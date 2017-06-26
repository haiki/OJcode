#include<iostream>
using namespace std;
//pay attention to presentation error!
int main()
{
    int n,k;//n:arr number; k:element number
    int arr[80];
    bool flag =0;
    while(cin>>n)
    {
        for(int j=0; j<n; j++)
        {
            cin>>k;
            flag=0;
            for(int i=0; i<k; i++)
            {
                cin>>arr[i];
            }
            if(arr[0]!=arr[1])
            {
                cout<<"0";
                flag=1;
            }

            for(int m=1; m<k-1; m++)
            {
                if((arr[m]>arr[m-1]&&arr[m]>arr[m+1])||(arr[m]<arr[m-1]&&arr[m]<arr[m+1]))
                {
                    if(flag)
                        cout<<" "<<m;
                    else
                    {
                        cout<<m;
                        flag=1;
                    }
                }
            }
            if(arr[k-2]!=arr[k-1])
            {
                if(flag)
                    cout<<" "<<k-1;
                else
                    cout<<k-1;
            }

            cout<<endl;
        }

    }

    return 0;
}
