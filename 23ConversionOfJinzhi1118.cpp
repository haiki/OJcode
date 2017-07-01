#include<iostream>
#include<string>
using namespace std;
//先转换成十进制数 然后由十进制数转换为对应的几进制
int main()
{
    int a,b;//a:before conversion b:after conversion
    string n;//n jin zhi shu
    while(cin>>a>>n>>b)
    {
        if(a<2||a>16||b<2||b>16)
             return 0;
        int sum=0;
        for(int i=0;i<n.size();i++)
        {
            int c=0;
            if(n[i]>='0'&&n[i]<='9')
            {
                c=n[i]-'0';

            }
            else if(n[i]>='a'&&n[i]<='f')
            {
                c=n[i]-'a'+10;
            }
            else
            {
                c=n[i]-'A'+10;
            }
            sum=sum*a+c;//critical!!!!

        }
        //shi jin zhi zhuan wei target
        char arr[40];
        int j=0;
//不可以用while do  要保证至少执行一次.比如0？
        do{
            int tmp=sum%b;
            arr[j++]=tmp<10?tmp+'0':tmp-10+'A';//critical,use stack too
            sum/=b;
        }while(sum);


        for(int k=j-1;k>=0;k--)
            cout<<arr[k];
        cout<<endl;
    }

return 0;

}
