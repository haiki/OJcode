#include<iostream>
using namespace std;
#define N 1000
//��������������м��ɣ����Լ�һ�£�
int main()
{
    int n,i,j;
    char c;
    int res[N];
    while(cin>>n)
    {
        res[0]=0;
        i=0;
        res[++i]=n;
        while(cin.get(c)&&(c=='+'||c=='-'||c=='*'||c=='/'))//��������cin����Ϊcin������һ����ֹ�ı�־��ctl+z��get�����س�ֹͣ����
    {
        cin>>n;
        if(c=='+')
            res[++i]=n;
        if(c=='-')
            res[++i]=-1*n;
        if(c=='*')
            res[i]*=n;
        if(c=='/')
            res[i]/=n;
    }
    for(j=1;j<=i;j++)
        res[0]+=res[j];
    cout<<res[0]<<endl;
    }

    return 0;
}
