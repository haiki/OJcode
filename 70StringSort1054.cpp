#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(char a,char b)//�������Ҫ˼·������һ���ֵĴ�����
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
        puts(arr);//ʹ����������Ҫ��c���Ե�����
    }
    return 0;
}
