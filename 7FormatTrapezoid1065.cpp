#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int h,m,n;//h:input height;m:largest row's number;n:each row's number
    while(cin>>h)
    {
        m=3*h-2;
        for(int i=0; i<h; i++)//control row
        {
            n=h+i*2;
            for(int j=0; j<m; j++)//column
            {
                if(j<m-n)
                    cout<<" ";
                else
                    cout<<"*";

            }
            cout<<endl;
        }

    }
    return 0;



}
