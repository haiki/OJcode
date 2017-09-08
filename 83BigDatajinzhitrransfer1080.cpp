#include<iostream>
#include<cstring>
#include<ctype.h>//用来判断是否是字母
using namespace std;
int main()
{
    int M,N;
    string X;
    while(cin>>M>>N)
    {
        cin>>X;
        int data[1010];
        int output[1010];
        int len=X.size();
        for(int i=0;i<len;i++)
        {
            if(isalpha(X[i]))
                data[i]=X[i]-'A'+10;
            else
                data[i]=X[i]-'0';
        }
        int sum=1,k=0;
        while(sum)
        {
            sum=0;
            for(int i=0;i<len;i++)
            {
                int d=data[i]/N;
                sum+=d;
                if(i==len-1)
                {
                    output[k++]=data[i]%N;
                }
                else
                {
                    data[i+1]+=(data[i]%N)*M;
                }
                data[i]=d;
            }
        }
        if(k==0)
            cout<<'0'<<endl;
        else
        {
            for(int i=k-1;i>=0;i--)
            {
                if(output[i]>9)
                    cout<<(char)(output[i]+'a'-10);
                else
                    cout<<output[i];

            }
            cout<<endl;
        }

    }
    return 0;

}
