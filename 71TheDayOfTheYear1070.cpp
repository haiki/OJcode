#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
#define ISLEAPYEAR(x) x%100!=0&&x%4==0||x%400==0?1:0
 int dayOfmonth[13][2]{
     0,0,
     31,31,
     28,29,
     31,31,
     30,30,
     31,31,
     30,30,
     31,31,
     31,31,
     30,30,
     31,31,
     30,30,
     31,31
 };
 struct date{
     int year,month,day;
     void nextDay()//计算下一天
     {
         day++;
         if(day>dayOfmonth[month][ISLEAPYEAR(year)])
         {
             day=1;
             month++;
             if(month>12)
             {
                 month=1;
                 year++;
             }
         }
     }
 };

/*int timeDiff(int ye,int mo,int da)//此时使用了函数调用，时间复杂度会非常大
{
    int days=0;
    for(int i=1000;i<ye;i++)
    {
        if(ISLEAPYEAR(i))
            days+=366;
        else
            days+=365;
    }
    int is_leap=ISLEAPYEAR(ye);
    for(int j=1;j<mo;j++)
    {
        days+=dayOfmonth[j][is_leap];
    }
    days+=da;
    return days;
}*/
int abs(int a)
{
    return a<0?-a:a;

}
int buf[5001][13][32];//通过预处理将所有与0年1月1日的时间差保存在数组中，在算的时候可以直接读取，使用了用空间换时间的方法
int main()
{
    /*int y,m,d;
    while(cin>>y>>m>>d)
    {
        int res=abs(timeDiff(y,m,d)-timeDiff(y,1,0));
        cout<<res<<endl;
    }*/

    date tmp;
    tmp.year=0;
    tmp.month=1;
    tmp.day=1;
    int cnt=0;//日期差
    while(tmp.year!=5001)
    {
        buf[tmp.year][tmp.month][tmp.day]=cnt;
        tmp.nextDay();
        cnt++;
    }
    int y,m,d;
    while(cin>>y>>m>>d)
    {
        int res=abs(buf[y][m][d]-buf[y][1][1]+1);
        cout<<res<<endl;
    }

    return 0;
}
