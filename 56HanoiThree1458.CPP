
#include<iostream>
using namespace std;
long long  Hanoi(int n)
{
    if(n==1)
        return 2;//�����ֻ��һ����Ҫ�ƶ�������Ҫ��������
    else
        return 3*Hanoi(n-1)+2;//����n-1���� A->C�������Ĵ�A->B����n-1��C->A�������Ĵ�B->C,n-1�ݹ�3�μ������Ĵ�A���ظ�����Ĵ�A->C
        //���ϣ���n-1����Ҫ3�εݹ顣��������һ����A->B->C
}
int main()
{
    int n;
    while(cin>>n)
    {
       cout<<Hanoi(n)<<endl;
    }
}