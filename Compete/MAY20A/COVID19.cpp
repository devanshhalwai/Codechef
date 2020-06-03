//https://www.codechef.com/MAY20B/problems/COVID19
#include <stdio.h>
#include <stdlib.h>
long int testcase,peoplesize,ans1,ans2,people[8],ekaage,ekpeeche,calculate;
void solve();
int main() 
{
    scanf("%ld",&testcase);
    for(long int i=0;i<testcase;i++)
    {
        scanf("%ld",&peoplesize);
        for(long int i=0;i<peoplesize;i++)
        {
            scanf("%ld",&people[i]);
        }
        solve();
    }
	return 0;
}
void solve()
{
    ans1=10000;
    ans2=-10000;
    for(long int i=0;i<peoplesize;i++)
    {
        ekpeeche=i-1;
        ekaage=i+1;
        while(ekpeeche>=0 && people[ekpeeche+1]-people[ekpeeche]<=2)
        {
            ekpeeche--;
        }
        while(ekaage<peoplesize && people[ekaage]-people[ekaage-1]<=2)
        {
            ekaage++;
        }
        calculate=ekaage-ekpeeche-1;
        if(ans1>calculate)
        {
            ans1=calculate;
        }
        if(ans2<calculate)
        {
            ans2=calculate;
        }
    }
    printf("%d %d\n",ans1,ans2);
}
