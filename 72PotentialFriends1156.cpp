#include<iostream>
using namespace std;
//�뵽�ˣ�û�и��õķ���ȥ�Ż�����ô����ȥ��һ�ԣ���Ҫ���գ����ݺ��٣�����ѭ��Ҳ�����кܴ��ʱ�临�Ӷ�
int Hash[201];
int main()
{
    int n,m;
    int res[201];//����ͳ��ÿ���˵�Ǳ������
    while(cin>>n>>m)
    {
        for(int i=1; i<=n; i++)
        {
            res[i]=0;//��ʼ��
            cin>>Hash[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(Hash[i]==Hash[j])
                   {
                       res[i]++;
                   }
            }
            res[i]-=1;//��Ϊÿ��һ�����Լ�������һ��
        }
        for(int i=1;i<=n;i++)
        {
            if(res[i]>0)
                cout<<res[i]<<endl;
            else
                cout<<"BeiJu"<<endl;
        }
        }
    return 0;

}
