//https://www.codechef.com/MAY20B/problems/CORUS
#include <stdio.h>
#include <stdlib.h>
int main() 
{
    long int testcase,size,queries,ans,isolationcenters;
    long int *corona = (long int*)calloc(26,sizeof(long int));
    scanf("%ld",&testcase);
    for(long int i=0;i<testcase;i++)
    {
        scanf("%ld%ld",&size,&queries);
        char inputstring[size];
        scanf("%s",inputstring);
        for(long int i=0;i<26;i++)
        {
            corona[i]=0;
        }
        for(long int i=0;i<size;i++)
        {
            corona[inputstring[i]-'a']=corona[inputstring[i]-'a']+1;
        }
        for(long int i=0;i<queries;i++)
        {
            ans=0;
            long int tempcorona[26];
            for(long int i=0;i<26;i++)
            {
                tempcorona[i]=corona[i];
            }
            scanf("%ld",&isolationcenters);
            for(long int i=0;i<26;i++)
            {
                tempcorona[i]=tempcorona[i]-isolationcenters;
            }
            for(long int i=0;i<26;i++)
            {
                if(tempcorona[i]>0)
                {
                    ans=ans+tempcorona[i];
                }
            }
            printf("%ld\n",ans);
        }
    }
	return 0;
}

