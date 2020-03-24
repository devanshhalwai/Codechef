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
        ll n,q,min=10000000001,max=0;
        cin>>n>>q;
        vector<ll> ip(n+1);
        for(ll i=1;i<=n;i++)
        {
            cin>>ip[i];
            if(ip[i]>max)
                max=ip[i];
            if(ip[i]<min)
                min=ip[i];
        }
        while(q--)
        {
            ll x1,x2,y,ans=0;
            cin>>x1>>x2>>y;
            if(y<min || y>max)
            {
                cout<<"0\n";
                continue;
            }
            else
            {
                for(ll j=x1;j<x2;j++)
                {
                    if((y>=ip[j] && y<=ip[j+1]) || (y<=ip[j] && y>=ip[j+1]))
                        ans++;
                }
            }
            cout<<ans<<"\n";
        }
    }
	return 0;
}