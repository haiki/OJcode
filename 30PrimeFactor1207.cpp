#include<iostream>
using namespace std;
#define N 1000000
bool mark[1000001];
int prime[1000001];
int pri_size=0;
void init()
{
    for(int i=2;i<1000001;i++)
        mark[i]=false;
    for(int j=2;j<1000001;j++)
    {
        if(mark[j]==true)
            continue;
        else
        {
            prime[pri_size++]=j;
            if(j>=1000) continue;
            for(int k=j*j;k<N+1;k+=j)
            {
                mark[k]=true;
            }
        }
    }
}
int main()
{
    init();
    int n;
    while(cin>>n)
    {
        int ansPrime[40]={0};//�ֽ���������
        int ansNum[40];//ÿ�������ӵĸ���
        int ansSize=0;//��ͬ�����ӵĸ���
        for(int i=0;i<pri_size;i++)
        {
            if(n%prime[i]==0)
            {
                ansPrime[ansSize]=prime[i];
                ansNum[ansSize]=0;//��ĳһ��Ԫ�س�ʼ��
                while(n%prime[i]==0)
                {
                    ansNum[ansSize]++;
                    n=n/prime[i];
                }
                ansSize++;//��һ��������
                if(n==1)
                    break;
            }
        }
        if(n!=1)
        {
            ansPrime[ansSize]=n;
            ansNum[ansSize++]=1;
        }
        int num=0;
        for(int j=0;j<ansSize;j++)
        {
            //cout<<ansPrime[j]<<"-"<<ansNum[j]<<" ";
            num+=ansNum[j];

        }
        cout<<num<<endl;
    }
    return 0;
}
