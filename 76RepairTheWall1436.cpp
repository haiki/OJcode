#include<iostream>
#include<algorithm>
using namespace std;
//�ܼ򵥵Ķ�����Ҫ�����ĳ�ƪ�����Ż���
bool cmp(int a,int b)//�����ƶ��������Ϊ�ɴ�С
{
    return a>b;
}
int main()
{
    int L,N;
    while(cin>>L>>N)
    {
        int buf[610];
        int ans=0;//������¼��Ҫ���ٸ�block
        for(int i=0;i<N;i++)
        {
            cin>>buf[i];
        }
        sort(buf,buf+N,cmp);
        int j;
        for(j=0;j<N;j++)
        {
            L-=buf[j];
            ans++;
            if(L<=0)
                break;
        }
        if(j==N)//��������ans����Ϊ�п���N=1
            cout<<"impossible"<<endl;
        else
            cout<<ans<<endl;

    }
    return 0;
}

