#include<iostream>
using namespace std;
long long  F[90];//�����һ�����飬��ô�Ͳ��ǵݹ���
int main()
{
    F[1]=1;
    F[2]=2;
    //forѭ�������þ���ֻ�ݲ��飬��ÿһ���������
    for(int i=3; i<=90; i++)
    {
        F[i]=F[i-1]+F[i-2];
    }
    //һ�ΰ�1-90��̨�׵����п��ܱ�������

    int n;
    while(cin>>n&&n>=1)
    {
        cout<<F[n]<<endl;
    }
    return 0;

}
