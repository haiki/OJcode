#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int num;
        for(int i=1;i<=n;i++)//��ʹ���������ʽ��ÿ����һ���������жϣ�������Ϊ��Ŀ�����������ܴ����Ժ�ʱ������
        {
            cin>>num;
            int q=(int)sqrt(num);//��������Ŀ������Ϊ��if(a*b==num&&a!=b),��ô����һ����ȻС��sqrt(num);
            int cnt=0,j;
            for(j=1;j<=q;j++)//ͨ��������sqrt(num)С��ÿ�����ҳ��ܹ���������һ��������num��Լ��
            {
                if(num%j==0)
                    cnt+=2;//��Ϊ����һ����aҲ��Ӧ��������һ����b
            }
            if(q*q==num)//��num�ܿ�������ƽ����ʱ��Ҫ�ټ���һ��
                cnt-=1;
            cout<<cnt<<endl;
        }
    }

    return 0;
}

