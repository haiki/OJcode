
#include<iostream>
using namespace std;
long long  Hanoi(int n)
{
    if(n==1)
        return 2;//如果是只有一个需要移动，则需要经过两次
    else
        return 3*Hanoi(n-1)+2;//首先n-1个从 A->C，将最大的从A->B，将n-1个C->A，将最大的从B->C,n-1递归3次加上最大的从A个重复上面的从A->C
        //以上，则n-1个需要3次递归。加上最大的一个从A->B->C
}
int main()
{
    int n;
    while(cin>>n)
    {
       cout<<Hanoi(n)<<endl;
    }
}
