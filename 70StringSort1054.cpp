#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(char a,char b)//本题的主要思路就是这一部分的代码了
{
        return a<b;
}
int main()
{
    char arr[201];
    while(cin>>arr)
    {
        int len=strlen(arr);
        sort(arr,arr+len,cmp);
        puts(arr);//使用这个语句需要用c语言的申明
    }
    return 0;
}
