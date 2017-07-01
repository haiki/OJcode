#include<iostream>
using namespace std;
char div[40]={0};//输入的字符数组，因为是大数据，所以longlong也不行
int divi[40]={0};//将输入转换为整数，方便dicide的操作
char resu[1000]={0};//数组大小至少为十进制数的3倍。存放二进制的结果。
int Divide(int len)//分割每一位，得到最后的余数
{
    int carry=0;
    for(int i=0;i<len;i++)
    {
        int num=(carry*10+divi[i])/2;
        carry=divi[i]%2;
        divi[i]=num;
    }
    return carry;

}
bool Is_Zero(int len)//从后往前判断商是否已经全部为0.因为在Divide函数中在前面的商就变为0了，所以不能从前往后
{
    for(int i=len-1;i>=0;i--)
    {
        if(divi[i]!=0)
            return false;
    }
    return true;
}

int main()
{
    while(cin>>div)
    {
        int len=0;//学会利用全局变量
        for(int i=0;div[i]!='\0';i++)
        {
            divi[i]=div[i]-'0';
            len++;
        }
        int re_size=0;
        do{
            resu[re_size++]=Divide(len)+'0';
        }while(!Is_Zero(len));
        for(int i=re_size-1;i>=0;i--)
        {
            cout<<resu[i];
        }

        cout<<endl;
    }
    return 0;
}
