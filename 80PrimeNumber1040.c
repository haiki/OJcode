#include<stdio.h>
#define N 1000000
int prime[N];
int mark[N];
//�����±��1��ʼ��ô����Ҫ��һ���洢�Ŀռ䣬������Ǳ߽�ֵ����ȷ��
void init()
{
    int i,j,k;
    /*for(k=1;k<=N;k++)
    {
            mark[k]=0;//����˫����
    }*/
    int size=1;
    for(i=2;i<=N;i++)
    {
        if(mark[i]==0)
        {
            prime[size++]=i;
            if(i>=10000)//�����Խ�磬�������ʵ�Ѿ������
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
