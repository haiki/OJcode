#include<iostream>

#include<cstring>//memset中要用到的头文件
using namespace std;
#define MOD 9973

int n;//把这个定义为全局的就很方便的可以在每一个函数中使用而且不用传参数，但是全局变量也因为大家都能用所以不安全，尽量少使用比较好
struct	Matrix{
    int mat[11][11];
};
Matrix operator *(Matrix a,Matrix b)
{

    Matrix c;
    memset(c.mat, 0, sizeof(c.mat));//必须要有这一句做一个清零的操作！其实我自己还是没有弄明白，有理解的麻烦留言！
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];//矩阵乘法运算法则，线性代数的理论知识化为代码实现
            }
            c.mat[i][j]%=MOD;//防止过大，做mod运算
        }
    }
    return c;
}
Matrix operator ^(Matrix a,int b)
{
    Matrix c;
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c.mat[i][j]=(i==j);//将此矩阵初始化为单位矩阵，这样就方便用来求快速幂，相当于一般方法中的res初始化
        }
    }
    //将方阵看作一个普通的数据结构进行快速幂求解
        while(b!=0)//==b&1
    {
        if(b&1)
            c=c*a;//单位矩阵和其他矩阵相乘仍然是其他矩阵
        b=b>>1;//==b/=2
        a=a*a;
    }
    return c;
}

int trA(Matrix a)
{
    int res=0,i;
    for(i=0;i<n;i++)
    {
        res+=a.mat[i][i];//求对角线之和
        res%=MOD;
    }
    return res;
}

int main()
{
    int T;//t组数据

    cin>>T;
    int k;//n:矩阵的行列，k幂数
    Matrix m;
    while(T--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>m.mat[i][j];
        }
       m= m^k;//矩阵幂的应用
        cout<<trA(m)<<endl;
    }
return 0;
}
