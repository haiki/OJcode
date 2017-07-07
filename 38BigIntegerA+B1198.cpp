#include<iostream>
#include<cstring>
using namespace std;
class BigInteger{
    public:
    int digit[1000];//每四位为一位保存
    int siz;//保存了多少个
    void init()
    {
        for(int i=0;i<1000;i++)
            digit[i]=0;
            siz=0;
    }
    void Set(char str[])
    {
        init();//少了这一句会导致runtime error  就是数组越界 除数为 0 这一类的错误
        int len=strlen(str);
        int j=0,tmp=0,c=1;
        for(int i=len-1;i>=0;i--)
        {

             tmp+=(str[i]-'0')*c;//从后往前加容易计算进位之类的
             j++;
             c*=10;//权重
             if(j==4||i==0)
             {
                 digit[siz++]=tmp;
                 j=0;
                 tmp=0;
                 c=1;
             }
        }
    }
    void output()
    {
        cout<<digit[siz-1];
        for(int i=siz-2;i>=0;i--)
        {
            if(digit[i]<10)
                cout<<"000"<<digit[i];
            else if(digit[i]<100)
                cout<<"00"<<digit[i];
            else if(digit[i]<1000)
                cout<<"0"<<digit[i];
            else
                cout<<digit[i];
        }
    }

 BigInteger operator + (const BigInteger &a)const
 {

     BigInteger ret;
     ret.init();

     int carry=0;//进位
     for(int i=0;i<a.siz||i<siz;i++)
     {
         int tmp=digit[i]+a.digit[i]+carry;
         carry=tmp/10000;
         tmp%=10000;
         ret.digit[ret.siz++]=tmp;
     }
     if(carry!=0)//最后一个进位
        ret.digit[ret.siz++]=carry;
     return ret;

 }
}a,b,c;
int main()
{
    char str1[1002],str2[1002];
    while(cin>>str1>>str2)
    {
        a.Set(str1);
        b.Set(str2);
        c=a+b;
        c.output();
        cout<<endl;
    }
    return 0;
}
