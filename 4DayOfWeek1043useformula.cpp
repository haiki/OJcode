#include<iostream>
#include<cstring>
using namespace std;
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

int main()
{
    int year=0,y=0,c=0,d=0,mon=0,w=0;//year,century,day,week.
    char m[20];//month
    while(cin>>d)
    {
        cin>>m>>year;
        for(int i=0; i<13; i++)
        {
            if(strcmp(m,month[i])==0)
            {
                mon=i;
                break;
            }
        }
        if(mon<3)
        {
            year-=1;
            mon+=12;
        }
        c=int(year/100);
        y=year-c*100;
        w=int(c/4)-2*c+y+int(y/4)+(26*(mon+1)/10)+d-1;
        w=(w%7+7)%7;
        cout<<week[w]<<endl;
    }
    return 0;
}
