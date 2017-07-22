#include<iostream>
using namespace std;
long long  F[90];//如果是一个数组，那么就不是递归了
int main()
{
    F[1]=1;
    F[2]=2;
    //for循环的作用就是只递不归，把每一项都存起来了
    for(int i=3; i<=90; i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    //一次把1-90个台阶的所有可能保存下来

    int n;
    while(cin>>n&&n>=1)
    {
        cout<<F[n]<<endl;
    }
    return 0;

}
