#include<iostream>
using namespace std;
//���û�а�����ĿҪ�����÷�Χ�Ļ������wrong answer��
//�������ⲻҪ̫���ӣ��ܲ�������Ͳ��á������ʼ��ֻ���ó�����ʾ��Χ
long int gcd(long int a,long int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int n,m;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {
            long int a,b;
            cin>>m>>a;
            m--;

            while(m!=0)
            {
                cin>>b;
                a=a*b/gcd(a,b);
                m--;
            }
            cout<<a<<endl;
        }
    }
    return 0;
}
