#include<iostream>
#include<cmath>
using namespace std;
 //�о������������ͬ���͵�����������ɴ����͵�С���;Ͳ���ǿ��ת���ˣ���double��int
//����һ��double��int����õ�һ��int����Ҫǿ��ת��
int main()
{
    int n,m;
    int left,right;
    int n_d,m_d,diff;
    int ans=0;
    while(cin>>m>>n)//�������ĿҪ�����ĸ���ǰ�ĸ��ں�
    {
        if(n==0&&m==0)
            break;

        left=right=m;

        n_d=log(n)/log(2)+1;//�����n���ڵ��ʱ������ȣ��൱�ڵ�n���ڵ��ڵڼ��㣻��ֻ�������ȫ������˵��
        m_d=log(m)/log(2)+1;//�����൱����ȡ��


        diff=n_d-m_d;//�����mΪ���ڵ�������Ҷ�ڵ�ĸ߶�

        for(int i=0;i<diff;i++)
        {
            left=2*left;
            right=right*2+1;//һֱ�ߵ�Ҷ�ڵ���һ��,����������Ը��ڵ㿪ʼ��һ·����һ·���ҵ���ײ㡣
        }

        ans=pow(2,diff)-1;//���������Щ��һ���ж��ٽڵ�
        if(right<=n)
            ans+=right-left+1;
        else if(left<=n)
            ans+=n-left+1;
        cout<<ans<<endl;

    }

    return 0;
}
