#include<iostream>
#include<stack>
using namespace std;
//wrong answer may means that your limit is not enough!
int main()
{
    stack <int>s;
    char buff1[120];

    while(cin>>buff1)
    {
        char buff2[120]={0};
        for(int i=0; buff1[i]!=0; i++)
        {
            if(buff1[i]=='(')
            {
                s.push(i);
                buff2[i]=' ';
            }
            else if(buff1[i]==')')
            {
                if(!s.empty())
                {
                    s.pop();
                    buff2[i]=' ';
                }
                else
                    {
                        buff2[i]='?';
                        }
            }
            else
            {
                buff2[i]=' ';
            }

        }
        while(!s.empty())
        {
            buff2[s.top()]='$';
            s.pop();
        }
        for(int j=0; buff1[j]!=0; j++)
        {
            cout<<buff1[j];
        }
        cout<<endl;
        for(int k=0; buff2[k]!=0; k++)
        {
            cout<<buff2[k];
            //buff2[k]='\0';
        }
        cout<<endl;
    }
    return 0;
}
