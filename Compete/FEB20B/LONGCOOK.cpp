//https://www.codechef.com/FEB20B/problems/LONGCOOK
#include<bits/stdc++.h> 
using namespace std;
long long int getWeekDay(long long int yy, int mm, int dd) 
{
	long long int rst =                                                     
		dd                                                      
		+ ((153 * (mm + 12 * ((14 - mm) / 12) - 3) + 2) / 5) 
		+ (365 * (yy + 4800 - ((14 - mm) / 12)))
		+ ((yy + 4800 - ((14 - mm) / 12)) / 4)
		- ((yy + 4800 - ((14 - mm) / 12)) / 100)
		+ ((yy + 4800 - ((14 - mm) / 12)) / 400)
		- 32045;
	return (rst+1)%7 ;
}
bool checkYear(long long int year) 
{  
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)); 
} 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int m1,m2,y1,y2;
        cin>>m1>>y1;
        cin>>m2>>y2;
        if(m1>2)
            y1++;
        if(m2<2)
            y2--;
        long long int ans=0;
        while(true)
        {
            if(y1%2000==0)
                break;
            else
            {
                if(getWeekDay(y1,2,1)==0 && !checkYear(y1))
                    ans++;
                else if(getWeekDay(y1,2,1)==6)
                    ans++;
                y1++;
            }
        }
        while(true)
        {
            if(y2%2000==0)
                break;
            else
            {
                if(getWeekDay(y2,2,1)==0 && !checkYear(y2))
                    ans++;
                else if(getWeekDay(y2,2,1)==6)
                    ans++;
                y2--;
            }
        }
        ans+=((y2-y1)/2000)*505;
        cout<<ans<<"\n";
    }
	return 0;    
}