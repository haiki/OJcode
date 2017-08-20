#include<iostream>
using namespace std;
//先完成排版，再输出
int main()
{
    char out,in;
    int n;

    while(cin>>n>>in>>out)
    {
        char gra[n+1][n+1];
        int num=0;
        for(int i=(n+1)/2;i>=1;i--)//首先找到最中间的左边。由里向外开始描绘整个图案
        {
            num++;//用来统计此次是偶数圈还是奇数圈，从而判断要用哪个字符来填充
            char c=num%2==1?in:out;
            for(int j=i;j<=n+1-i;j++)//n+1-j就是这个框的长度，但是我还是想不出这个规律
            {
                gra[i][j]=c;//首先找到左上角的
                gra[n+1-i][j]=c;//与1关于水平线对称
                gra[j][i]=c;//与1关于对角线对称
                gra[j][n+1-i]=c;//与1关于垂直线对称
            }
        }
        if(n!=1)//当不是只有一行的时候。把四个角打平
        {
            gra[1][1]=' ';
            gra[1][n]=' ';
            gra[n][1]=' ';
            gra[n][n]=' ';
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                cout<<gra[i][j];
            cout<<endl;
        }
        cout<<endl;


    }


    return 0;
}
