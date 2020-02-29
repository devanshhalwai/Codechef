//https://www.codechef.com/LTIME81B/problems/POPGATES
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
        ll n,k;
        cin>>n>>k;
        std::vector<char> ip(n);
        for(ll i=0;i<n;i++)
            cin>>ip[i];
        for(ll i=0;i<k;i++)
        {
            char temp=ip[ip.size()-1];
            ip.pop_back();
            if(temp=='H')
            {
                for(ll j=0;j<ip.size();j++)
                {
                    if(ip[j]=='H')
                        ip[j]='T';
                    else
                        ip[j]='H';
                }
            }
        }
        ll ans=0;
        for(ll i=0;i<ip.size();i++)
            if(ip[i]=='H')
                ans++;
        cout<<ans<<"\n";
    }
	return 0;
}