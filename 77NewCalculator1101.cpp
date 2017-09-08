#include<iostream>
using namespace std;
#define N 1000
//这道计算器的题有技巧，可以记一下！
int main()
{
    int n,i,j;
    char c;
    int res[N];
    while(cin>>n)
    {
        res[0]=0;
        i=0;
        res[++i]=n;
        while(cin.get(c)&&(c=='+'||c=='-'||c=='*'||c=='/'))//不可以用cin，因为cin必须有一个终止的标志如ctl+z，get遇到回车停止读入
    {
        cin>>n;
        if(c=='+')
            res[++i]=n;
        if(c=='-')
            res[++i]=-1*n;
        if(c=='*')
            res[i]*=n;
        if(c=='/')
            res[i]/=n;
    }
    for(j=1;j<=i;j++)
        res[0]+=res[j];
    cout<<res[0]<<endl;
    }

    return 0;
}
