#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int num;
        for(int i=1;i<=n;i++)//不使用数组的形式，每输入一个数就做判断，可能因为题目给的数据量很大所以耗时很严重
        {
            cin>>num;
            int q=(int)sqrt(num);//这样做的目的是因为：if(a*b==num&&a!=b),那么其中一个必然小于sqrt(num);
            int cnt=0,j;
            for(j=1;j<=q;j++)//通过遍历比sqrt(num)小的每个数找出能够整除的那一个，则是num的约数
            {
                if(num%j==0)
                    cnt+=2;//因为整除一个数a也对应于整除另一个数b
            }
            if(q*q==num)//当num能开整数的平方的时候，要少计算一个
                cnt-=1;
            cout<<cnt<<endl;
        }
    }

    return 0;
}

