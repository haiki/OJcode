#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Student{
    char id[7] ;
    char name[9] ;
    int score;
    bool operator <(const Student&s)const
    {
        return s.id<id;
    }
}stu[100001];
bool cmp1(Student a,Student b)
{
    int tmp=strcmp(a.name,b.name);
    if(tmp!=0)
        return tmp<0;
    else
        return a.id<b.id;
}

bool cmp2(Student a,Student b)
{
    if(a.score!=b.score)
        return a.score<b.score;
    else
        return a.id<b.id;
}
int main(){
    int n,c;
    while(cin>>n&&c!=0)
    {
        cin>>c;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cin>>stu[i].id>>stu[i].name>>stu[i].score;
        }
        switch(c)
        {
            case 1: sort(stu,stu+n);break;
            case 2: sort(stu,stu+n,cmp1);break;
            case 3: sort(stu,stu+n,cmp2);break;
        }
        cout<<"Case "<<cnt+1<<":"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<" "<<stu[i].id<<" "<<stu[i].name<<" "<<stu[i].score<<endl;
        }

    }




    return 0;
}
