#include<iostream>
#include<cmath>
using namespace std;
bool judge(int n)
{
    if(n<=1) return false;
    int m=(int)sqrt(n)+1;//mΪö���Ͻ죬+1��Ϊ�����ɶ�ö��һ����Ҳ���ܷŹ�һ��
    for(int j=2;j<m;j++)
    {
        if(n%j==0)
            return false;
    }
    return true;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(judge(n))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
