#include<iostream>
#include<algorithm>
using namespace std;
/*int BinarySearch(int arr[],int left,int right,int sear)
{
    while(left<=right){
        int mid=(left+right)/2;
        if(arr[mid]=sear)
            return mid;
        else if(arr[mid]>sear)
            right=mid-1;
        else
            left=mid+1;
    }
    if(left>right)
        return -1;

}

int main()
{
    int buff[200];
    int n,x;//n:number of input;x:which need to be find;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            {
                cin>>buff[i];
            }
            sort(buff,buff+n);
            for(int i=0;i<n;i++)
            {
                cout<<buff[i]<<" ";
            }

            cin>>x;
            cout<<endl<<BinarySearch(buff,0,n-1,x)<<endl;

    }
    return 0;
}
*/
int main()
{
    int buff[200];
    int n,x;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            {
                cin>>buff[i];
            }
            cin>>x;

            int j;
            for(j=0;j<n;j++)
            {
                if(buff[j]==x)
                   {
                       cout<<j<<endl;
                       break;
                   }
            }
            if(j==n)
                cout<<"-1"<<endl;
    }
    return 0;
}
