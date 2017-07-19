#include<iostream>
using namespace std;
int main(){
    int i,j,k;
    for(i=0;i<=5;i++)
    {
        for(j=0;j<=5;j++)
        {
               // b=b1=j;
               for(k=0;k<=9;k++)
               {

                if((i+j)*100+(j+k)*10+2*k==532)
                    cout<<i<<" "<<j<<" "<<k<<endl;
               }
        }
    }

return 0;

}
