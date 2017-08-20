#include<iostream>
#include<algorithm>
using namespace std;
bool Find(int l,int r,int arr[],int a)
{
    int left=l,right=r,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(arr[mid]<a)
            left=mid+1;
        else if(arr[mid]>a)
            right=mid-1;
        else
            return true;
    }
return false;
}

int main()
{
    int n,m,fi;
    int arr[101];
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cin>>m;
        for(int j=0; j<m; j++)
        {
            cin>>fi;
            bool f=Find(0,n-1,arr,fi);//n-1!!!no n!
            if(f)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }

    }


    return 0;
}
