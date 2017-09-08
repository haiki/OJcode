
#include<iostream>
#include<cstring>
#include<vector>


using namespace std;

struct BigData
{
    int buf[100];
    int s;
    void init()
    {
        for(int i=0; i<100; i++)
        {
            buf[i]=0;
        }
        s=0;
    }
    void Set(char arr[])
    {
        init();//这家伙很重要！！！但是就是不知道什么时候写
        int len=strlen(arr);
        int c=1,j=0,tmp=0;
        for(int i=len-1; i>=0; i--) //最后的i是--！！！倒着存进去，为了进位时数组长度的动态变化
        {
            tmp=(arr[i]-'0')*c+tmp;//注意这里的arr[i]不是整数
            c*=10;//每一位的权值
            j++;//四位为一个数组位
            if(j==4||i==0)
            {
                buf[s++]=tmp;
                c=1;
                j=0;
                tmp=0;
            }
        }
    }
    BigData operator +(const BigData &A)const
    {
        BigData ret;//存放要返回的结果
        ret.init();
        int carry=0;//余数
        for(int i=0; i<s||i<A.s; i++)
        {
            int tmp=buf[i]+A.buf[i]+carry;
            ret.buf[ret.s++]=tmp%10000;
            carry=tmp/10000;
        }
        if(carry!=0)//写代码的时候要考虑完所有的情况
            ret.buf[ret.s++]=carry;
        return ret;
    }
    BigData operator *(const int &x)const
    {
        BigData ret;
        ret.init();
        int carry=0;
        for(int i=0; i<s; i++)
        {
            int tmp=buf[i]*x+carry;
            ret.buf[ret.s++]=tmp%10000;
            carry=tmp/10000;
        }
        if(carry!=0)//写代码的时候要考虑完所有的情况
            ret.buf[ret.s++]=carry;
        return ret;
    }
    int operator %(const int &x)const
    {
        int r=0;
        for(int i=s-1; i>=0; i--)
        {
            r=((r*10000)+buf[i])%x;//你要给谁取余就写多少！！
        }
        return r;
    }
    bool operator <(const BigData &A)const
    {
        if(s!=A.s)
            return s<A.s;
        else
            for(int i=s-1; i>=0; i--)
            {
                if(buf[i]!=A.buf[i])
                    return buf[i]<A.buf[i];
            }
    }
};

struct E
{
    int next;
    BigData cost;
};

vector<E> edge[102];
BigData dis[102];
bool mark[102];
bool flag[102];
int main()
{
    int n,m;
    while(cin>>n>>m&&n!=0&&m!=0)
    {

        for(int i=0; i<n; i++)
            edge[i].clear();//这个很重要啊！！不清除干净，下次用的时候就会重复了啊

        BigData cos;
        cos.Set("1");
       // cout<<"+";
        for(int i=0; i<m; i++)
        {
            int a,b;
            cin>>a>>b;
            E tmp;
            tmp.cost=cos;
            cos=cos*2;
            tmp.next=b;
            edge[a].push_back(tmp);
            tmp.next=a;
            edge[b].push_back(tmp);
        }
        for(int i=0; i<n; i++)
        {
            dis[i].init();
            mark[i]=false;
            flag[i]=false;
        }
        dis[0].Set("0");
        mark[0]=true;//已经被访问过，即加入集合了
        flag[0]=true;//距离不是不可达
        int newp=0;//新加入集合的点
        for(int i=1; i<n; i++) //依次加入点，共进行n-1次
        {

            for(int j=0; j<edge[newp].size(); j++)//写错一个小的变量，结果就会出错
            {
                int t=edge[newp][j].next;
                BigData d=edge[newp][j].cost;
                if(mark[t]==true)
                    continue;
                if(flag[t]==false||dis[newp]+d<dis[t])
                {
                    dis[t]=dis[newp]+d;//operator +
                    flag[t]=true;
                }
            }

            BigData Min;
            Min.Set("999999999999999999999999999999");


            for(int i=1; i<n; i++)
            {
                if(mark[i]==true) continue;
                if(flag[i]==false) continue;
                if(dis[i]<Min)//operator <
                {
                    Min=dis[i];
                    newp=i;
                }
            }
            mark[newp]=true;
        }

        for(int i=1; i<n; i++)
        {
            if(flag[i]==false)
                cout<<"-1"<<endl;
            else
                cout<<dis[i]%100000<<endl;//把题目中要求取余多少的零数清楚！！
        }
    }


    return 0;
}







