#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

class Student
{
public:
    char name[101];
    int score;
    int age;
    /*void input()
    {
    cin>>name>>age>>score;
    }*/
    bool operator<(const Student&b)const
    {
        if(score!=b.score)//why here need to be !=?
            return score<b.score;//当返回值为true，则函数的死一个参数会排在第二个参数前面
        int tmp=strcmp(name,b.name);
        if(tmp!=0)
            return tmp<0;
        else
            return age<b.age;

    }
} stu[1000];
//cmp只需要将重载运算符的语句转换成相关的语句，并且在sort中将cmp作为参数加进去
/*bool cmp(Student a,Student b){
    if(a.score<b.score)
        return a.score<b.score;//当返回值为true，则函数的死一个参数会排在第二个参数前面
    int tmp=strcmp(a.name,b.name);
    if(tmp!=0)
        return tmp<0;
    else
        return a.age<b.age;
}*/

int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0; i<n; i++)
        {

            cin>>stu[i].name>>stu[i].age>>stu[i].score;
            //stu[i].input();
        }
        //sort(stu,stu+n,cmp);
        sort(stu,stu+n);
        for(int j=0; j<n; j++)
        {
            cout<<stu[j].name<<" "<<stu[j].age<<" "<<stu[j].score;
            cout<<endl;
        }
    }
    return 0;


}
