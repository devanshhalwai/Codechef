//https://www.codechef.com/FEB20B/problems/CASH
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,k,taken_out=0;
        cin>>n>>k;
        long long int a;
        if(n==1)
        {
            cin>>a;
            cout<<a%k<<"\n";
        }
        else
        {
            for(int i=1;i<n;i++)
            {
                cin>>a;
                taken_out+=a%k;
            }
            if(n>1)
            {
                cin>>a;
                if(taken_out>=(k-(a%k)))
                {
                    taken_out-=(k-(a%k));
                    long long int remaining_multiple=(long long int)taken_out/k;
                    taken_out-=k*remaining_multiple;
                }
                else
                    taken_out+=a%k;
            }
            cout<<taken_out<<"\n";
        }
    }
    return 0;
}