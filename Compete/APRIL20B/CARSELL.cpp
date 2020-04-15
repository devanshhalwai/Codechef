//https://www.codechef.com/APRIL20B/problems/CARSELL
#include <iostream>
#include <bits/stdc++.h>
#include <utility>
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
        ll n,no_of_zero;
        cin>>n;
        vector<ll> ip(n);
        for(ll i=0;i<n;i++)
            cin>>ip[i];
        sort(ip.begin(),ip.end(),greater<ll>());
        ll profit=ip[0];
        profit%MOD;
        for(ll i=1;i<n;i++)
        {
            ip[i]=((ip[i]-i)>0)?(ip[i]-i):0;
            profit+=ip[i];
            profit=profit%MOD;
        }
        cout<<profit<<endl;
    }
	return 0;
}

