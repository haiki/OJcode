#include<iostream>
using namespace std;
//������Ű棬�����
int main()
{
    char out,in;
    int n;

    while(cin>>n>>in>>out)
    {
        char gra[n+1][n+1];
        int num=0;
        for(int i=(n+1)/2;i>=1;i--)//�����ҵ����м����ߡ��������⿪ʼ�������ͼ��
        {
            num++;//����ͳ�ƴ˴���ż��Ȧ��������Ȧ���Ӷ��ж�Ҫ���ĸ��ַ������
            char c=num%2==1?in:out;
            for(int j=i;j<=n+1-i;j++)//n+1-j���������ĳ��ȣ������һ����벻���������
            {
                gra[i][j]=c;//�����ҵ����Ͻǵ�
                gra[n+1-i][j]=c;//��1����ˮƽ�߶Գ�
                gra[j][i]=c;//��1���ڶԽ��߶Գ�
                gra[j][n+1-i]=c;//��1���ڴ�ֱ�߶Գ�
            }
        }
        if(n!=1)//������ֻ��һ�е�ʱ�򡣰��ĸ��Ǵ�ƽ
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
