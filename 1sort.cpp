/*

题目描述：

        对输入的n个数进行排序并输出。

输入：

        输入的第一行包括一个整数n(1<=n<=100)。
        接下来的一行包括n个整数。

输出：

        可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。
        每组测试数据的结果占一行。

*/
#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int x,int y){
    return x>y;//定义的规则中，cmp表示第一个参数是否比第二个参数大，若是，则排在前面
}
int main()
{
    int buff[100];
    int n;

    while(cin>>n)
    {
        bool flag=false;
        for(int k=0; k<n; k++)
        {
            cin>>buff[k];
        }
        sort(buff,buff+n,cmp);
        /*for(int i=0; i<n; i++)
        {
            if(!flag)
            {
                flag=true;
                for(int j=1; j<n-i; j++)
                {
                    if(buff[j-1]>buff[j])
                    {
                        flag=false;
                        int tmp=buff[j-1];
                        buff[j-1]=buff[j];
                        buff[j]=tmp;

                    }
                }
            }
        }*/
        for(int i=0; i<n; i++)
        {
            cout<<buff[i]<<" ";
        }
        cout<<endl;
    }
    return 0;


}
