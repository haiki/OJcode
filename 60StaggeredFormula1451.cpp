#include<iostream>
using namespace std;
long long F[21];
//int n;
int main()
{
    F[1]=0;
    F[2]=1;
    for(int i=3;i<=20;i++)
    {
        F[i]=(i-1)*(F[i-1]+F[i-2]);
    }
    int n;
    while(cin>>n)
    {
        cout<<F[n]<<endl;
    }
    return 0;

}
