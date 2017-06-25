#include<iostream>
#include<cstdlib>//abs
using namespace std;
#define ISLEAP(x) x%100!=0&&x%4==0||x%400==0?1:0
//pay attention to regular,no comma;
int DayOfMonth[13][2]=
{
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
// Time difference
int TimeDiff(int date)
{
    int days=0;
    int year=date/10000;
    int month=(date%10000)/100;
    int day=date%100;


    for(int i=1; i<year; i++)
    {
        if( ISLEAP(i))
            days+=366;
        else
            days+=365;

    }

    int is_leap=ISLEAP(year);
    for(int j=1; j<month; j++)
    {
        days+=DayOfMonth[j][is_leap];
    }
    days+=day;
    return days;
}
int main()
{
    int da1=0,da2=0;//input integer :yymmdd

    while(cin>>da1)
    {
        cin>>da2;
        int diff=abs(TimeDiff(da2)-TimeDiff(da1)+1);
        cout<<diff<<endl;
    }
    return 0;
}
