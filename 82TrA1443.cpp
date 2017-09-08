#include<iostream>

#include<cstring>//memset��Ҫ�õ���ͷ�ļ�
using namespace std;
#define MOD 9973

int n;//���������Ϊȫ�ֵľͺܷ���Ŀ�����ÿһ��������ʹ�ö��Ҳ��ô�����������ȫ�ֱ���Ҳ��Ϊ��Ҷ��������Բ���ȫ��������ʹ�ñȽϺ�
struct	Matrix{
    int mat[11][11];
};
Matrix operator *(Matrix a,Matrix b)
{

    Matrix c;
    memset(c.mat, 0, sizeof(c.mat));//����Ҫ����һ����һ������Ĳ�������ʵ���Լ�����û��Ū���ף��������鷳���ԣ�
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                c.mat[i][j]+=a.mat[i][k]*b.mat[k][j];//����˷����㷨�����Դ���������֪ʶ��Ϊ����ʵ��
            }
            c.mat[i][j]%=MOD;//��ֹ������mod����
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
            c.mat[i][j]=(i==j);//���˾����ʼ��Ϊ��λ���������ͷ�������������ݣ��൱��һ�㷽���е�res��ʼ��
        }
    }
    //��������һ����ͨ�����ݽṹ���п��������
        while(b!=0)//==b&1
    {
        if(b&1)
            c=c*a;//��λ������������������Ȼ����������
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
        res+=a.mat[i][i];//��Խ���֮��
        res%=MOD;
    }
    return res;
}

int main()
{
    int T;//t������

    cin>>T;
    int k;//n:��������У�k����
    Matrix m;
    while(T--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cin>>m.mat[i][j];
        }
       m= m^k;//�����ݵ�Ӧ��
        cout<<trA(m)<<endl;
    }
return 0;
}
