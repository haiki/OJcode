#include<iostream>
#include<cstdlib>//abs
#include<cstring>
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
char month[13][20]=
{
    " ",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};
char week[7][20]=
{
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};
// Time difference
int TimeDiff(int day,int mo,int ye)
{
    int days=0;
    for(int i=1000; i<ye; i++)
    {
        if( ISLEAP(i))
            days+=366;
        else
            days+=365;

    }

    int is_leap=ISLEAP(ye);
    for(int j=1; j<mo; j++)
    {
        days+=DayOfMonth[j][is_leap];
    }
    days+=day;
    return days;
}
int main()
{
    int day=0,year=0,m=0,w=0;
    char mon[20];

   while(cin>>day)
    {
        cin>>mon>>year;
        for(int i=1; i<13; i++)
        {
            if(strcmp(mon,month[i])==0)
            {
                m=i;
                break;
            }
        }
       //cout<<abs(TimeDiff(15,11,2001)-TimeDiff(14,11,2001));
        int diff=TimeDiff(day,m,year)-TimeDiff(25,6,2017);
        //cout<<diff;
        int w=(diff%7+7)%7;
        cout<<week[w]<<endl;
    }
    return 0;
}
