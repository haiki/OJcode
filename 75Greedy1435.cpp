#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
//��ʵ����Ⲣû���������ô�ѣ�
//��Ϊÿһ��Ũ������Ӧ�������һ���ģ�����û�б�Ҫдһ���ṹ�塣ֱ�ӽ�Ũ����һ�������ʾ������
//�������� ��Ϊ��double��ֱ����sort�Ϳ��ԣ�����ʲô���õ�operator
//����  ��ac���Ǻܿ��ĵģ�
struct Solution
{
    double con;//Ũ�ȣ�concentration
    bool operator<(const Solution&E)const
    {
        return con<E.con;
    }

} s[101];
int main()
{
    int c;//���Ե�����

    while(cin>>c)
    {
        for(int i=0; i<c; i++)
        {
            int n,v;
            double w;
            cin>>n>>v>>w;
            w/=100;
            for(int j=0; j<n; j++)
            {
                cin>>s[j].con;
                //s[j].vol=v;
                s[j].con/=100;
            }
            sort(s,s+n);
            Solution mix;
            int cur_vol=0;
            double cur_con= mix.con=0.00;
            int k;
            for(k=0; k<n; k++)
            {
                   mix.con=(double)(cur_con*cur_vol+s[k].con*v)/(double)(cur_vol+v);//һ���������ֵ���ڱȽ��Ƿ�������������һ��cur����ʵʱ�����
                   //cout<<setprecision(2)<<std::fixed<<mix.con<<endl;
                if(mix.con-0.0000001<=w)//�������ľ����ж���һ���ѵ�
                {
                    cur_con=mix.con;
                    cur_vol+=v;
                 // cout<<cur_vol<<" "<<setprecision(2)<<std::fixed<<cur_con<<endl;
                }
                else
                    break;
            }
            if(k==0)
                cout<<"0"<<" "<<"0.00"<<endl;
            else
                cout<<cur_vol<<" "<<setprecision(2)<<std::fixed<<cur_con<<endl;

        }
    }

    return 0;
}
