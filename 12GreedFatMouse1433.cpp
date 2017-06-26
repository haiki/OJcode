#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class goods
{
public:
    double f;//finance :money:cat's Food
    double p;//goods'pound:JavaBean
    double c;//j/m:cost performance
    bool operator <(const goods& g)const
    {
        return c>g.c;
    }
} buff[1000];
int main()
{
    double m;
    int n;//m:money;n:n house/chose
    while(cin>>m)
    {
        cin>>n;
        if(m==-1&&n==-1)
            break;
        else
        {
            for(int i=0; i<n; i++)
            {
                cin>>buff[i].p>>buff[i].f;
                buff[i].c=buff[i].p/buff[i].f;
            }
            sort(buff,buff+n);
            int index=0;//current home index;
            double sum=0;//obtain goods;
            while(m>0&&index<n)
            {
                if(m>buff[index].f)//can buy total goods
                {
                    sum+=buff[index].p;
                    m-=buff[index].f;
                }
                else//use remain money to buy goods
                {
                    sum+=m*buff[index].p/buff[index].f;
                    m=0;
                }
                index++;//buy next house'goods
            }
            cout<<fixed<<setprecision(3)<<sum<<endl;

        }
    }
return 0;

}


