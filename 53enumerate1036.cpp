
#include<iostream>
using namespace std;
//��ΪҪȡ������ֵ�����ԴӴ�С��ѭ����һ�ֿ��ٶ����Ǽ��ķ�����
//break��������ǰ��ѭ������һ��ѭ��
int main()
{
    int n;//turkey ��s number
    while(cin>>n)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int num=x*100+y*10+z;
        int i,j;
        bool flag=false;
        for(i=9; i>=1; i--)
        {
            for(j=9; j>=0; j--)
            {
                int sum=10000*i+10*num+j;
                if(sum%n==0)
                {
                    flag=true;
                    cout<<i<<" "<<j<<" "<<sum/n<<endl;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(flag==false)
            cout<<"0"<<endl;
    }
    return 0;

}

