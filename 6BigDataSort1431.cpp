#include<iostream>
using namespace std;
#define OFFSET 500000
int Hash[1000001];
int main()
{
    int n,m;

    while(cin>>n>>m)
    {
        for(int i=-500000; i<=500000; i++)//���һ��Ҫ����while���棬�����������ʱ����ظ������
        {
            Hash[i+OFFSET]=0;
        }

        for(int j=1; j<=n; j++)//ע��߽�ȡֵ��j<=n
        {
            int num;
            cin>>num;
            Hash[num+OFFSET]=1;
        }
        bool flag=false;
        for(int k=500000; k>=-500000&&m!=0; k--)
        {
            if(Hash[k+OFFSET]==1)
            {
                if(flag==false)
                    {
                        flag=true;
                        cout<<k;
                        m--;//Ϊʲô�����԰�m�ı仯����forѭ�����п����Ƕ��ŵ����ȼ�ʹ��ѭ��û����ֹ
                    }
                else{
                    cout<<" "<<k;
                    m--;
                }
                /*cout<<k;
                m--;
                if(m!=0)
                    cout<<" ";
                else
                {
                    cout<<endl;
                    break;
                }*/
            }
        }
    }
    return 0;

}
