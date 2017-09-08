#include<stdio.h>
#define N 1000000
int prime[N];
int mark[N];
//数组下标从1开始那么就需要多一个存储的空间，否则就是边界值不正确了
void init()
{
    int i,j,k;
    /*for(k=1;k<=N;k++)
    {
            mark[k]=0;//不是双等于
    }*/
    int size=1;
    for(i=2;i<=N;i++)
    {
        if(mark[i]==0)
        {
            prime[size++]=i;
            if(i>=10000)//下面会越界，后面的其实已经标好了
                continue;
            for(j=i*i;j<=N;j+=i)
                mark[j]=1;
        }
    }
}
int main()
{
    init();
    int n;
    prime[0]=0;
    while(scanf("%d",&n)!=EOF)
        {
            printf("%d\n",prime[n]);
            }

    return 0;



}
