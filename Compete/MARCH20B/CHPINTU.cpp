//https://www.codechef.com/MARCH20B/problems/CHPINTU
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define endl "\n"
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m,temp,min=92233720368547758;
        cin>>n>>m;
        vector<ll> ip(n);
        unordered_map<ll,ll> calc;
        for(ll i=0;i<n;i++)
            cin>>ip[i];
        for(ll i=0;i<n;i++)
        {
            cin>>temp;
            calc[ip[i]]+=temp;
        }
        for(auto i:calc)
            if(i.second<min)
                min=i.second;
        cout<<min<<"\n";
    }
	return 0;
}
  
