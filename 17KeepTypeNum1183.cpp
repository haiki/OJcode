#include<iostream>
using namespace std;
//һ��Ҫ��ϸ������������Ǵ�д����Сд

int main()
{
    int a,b;//a:input number;b:a^2;
    while(cin>>a)
    {
        b=a*a;
        if(a<10)
        {
            if(b%10==a)
                cout<<"Yes!"<<endl;
            else
                cout<<"No!"<<endl;
        }
        else
        {
            if(b%100==a)
                cout<<"Yes!"<<endl;
            else
                cout<<"No!"<<endl;
        }

    }
    return 0;
}
