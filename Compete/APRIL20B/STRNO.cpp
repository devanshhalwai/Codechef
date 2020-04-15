//https://www.codechef.com/APRIL20B/problems/STRNO
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007
int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll x,k;
        cin>>x>>k;
        ll exponent=0;
        while(x%2==0)
        {
            x=x/2;
            exponent++;
        }
        for(ll i=3;i*i<=x;i+=2)
        {
            while(x%i==0)
            {
                x=x/i;
                exponent++;
            }
        }
        if(x>2)
            exponent++;
        if(exponent>=k)
            cout<<"1\n";
        else
            cout<<"0\n";
    }
	return 0;
}
