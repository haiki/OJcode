#include<iostream>
using namespace std;
/*int main(){
    int n;
    while(cin>>n&&n!=0)
    {
        int Hash[101]={0};//record the occurrence of one grade,every circle must initialize Hash
        for(int i=0;i<n;i++)
        {
            int gra;
            cin>>gra;
            Hash[gra]+=1;
        }
        int grade;
        cin>>grade;
        cout<<Hash[grade]<<endl;
    }
        return 0;

}*/
int main()
{
    int n;//numbers
    int grade;//uesed to find equal grade
    int gra[1001];

    while(cin>>n&&n!=0)
    {
        for(int i=0; i<n; i++)
        {
            cin>>gra[i];
        }
        cin>>grade;
        int num=0;
        for(int j=0; j<n; j++)
        {
            if(grade==gra[j])
                num++;
        }
        cout<<num<<endl;
    }
    return 0;
}
