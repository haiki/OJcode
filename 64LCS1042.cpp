#include<iostream>
#include<cstring>
using namespace std;
int max_num(int a,int b)
{
    return a>b?a:b;
}

int state[101][101];//buff1中前i个字符和buff2中前j个字符公共字串的长度
int main()
{
    char buf1[101];
    char buf2[101];
    while(cin>>buf1)
    {
        cin>>buf2;
        int len1=strlen(buf1);
        int len2=strlen(buf2);

        //初始化，当前0个和另一个字符串的比较的时候公共的字符串长度就为0
        for(int i=0; i<=len1; i++)
        {
            state[i][0]=0;
        }
        for(int j=0; j<=len2; j++)
        {
            state[0][j]=0;
        }


        for(int i=1; i<=len1; i++)
        {
            for(int j=1; j<=len2; j++)
            {
                if(buf1[i-1]==buf2[j-1])//下标从1开始，所以i-1代表当前的字符。
                {
                    state[i][j]=state[i-1][j-1]+1;
                }
                else
                {
                    state[i][j]=max_num(state[i][j-1],state[i-1][j]);
                }
            }
        }
        cout<<state[len1][len2]<<endl;
    }
    return 0;

}
