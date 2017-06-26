#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
class Stu
{
    public:
    char id[100];
    string name;
    string sex;
    int age;
    bool operator <(const Stu &s)const
    {
        return strcmp(id,s.id)<0;
    }
} stu[1000];
int BinarySearch(Stu arr[],int left,int right,char sear[])
{
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(strcmp(arr[mid].id,sear)==0)
            return mid;
        else if(strcmp(arr[mid].id,sear)>0)
            right=mid-1;
        else
            left=mid+1;
    }
    if(left>right)
        return -1;
}

int main()
{
    int n,m;//n student's info; search for m times
    while(cin>>n&&n<=1000)
    {
        for(int i=0; i<n; i++)
        {
            cin>>stu[i].id>>stu[i].name>>stu[i].sex>>stu[i].age;
        }
        sort(stu,stu+n);
        cin>>m;
        char sea[30];
        for(int j=0; j<m; j++)
        {
            cin>>sea;
            int index=BinarySearch(stu,0,n-1,sea);
            if(index!=-1)
                cout<<stu[index].id<<" "<<stu[index].name<<" "<<stu[index].sex<<" "<<stu[index].age<<endl;
            else
                cout<<"No Answer!"<<endl;
        }

        return 0;
    }

}
