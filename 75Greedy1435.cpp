#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
//其实这道题并没有想象的那么难，
//因为每一个浓度所对应的体积是一样的，所以没有必要写一个结构体。直接将浓度用一个数组表示就行了
//至于排序 因为是double，直接用sort就可以，不用什么内置的operator
//不过  能ac还是很开心的！
struct Solution
{
    double con;//浓度：concentration
    bool operator<(const Solution&E)const
    {
        return con<E.con;
    }

} s[101];
int main()
{
    int c;//测试的组数

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
                   mix.con=(double)(cur_con*cur_vol+s[k].con*v)/(double)(cur_vol+v);//一个算出来的值用于比较是否满足条件，另一个cur用来实时的输出
                   //cout<<setprecision(2)<<std::fixed<<mix.con<<endl;
                if(mix.con-0.0000001<=w)//浮点数的精度判断是一个难点
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
