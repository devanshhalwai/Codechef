//https://www.codechef.com/LTIME84A/problems/WWALK
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
    ll n;
    cin>>n;
    vector<ll> a(n),b(n),dista(n+1),distb(n+1);
    dista[0]=0;
    distb[0]=0;
    for(ll i=0;i<n;i++)
        cin>>a[i];
    for(ll i=0;i<n;i++)
        cin>>b[i];
    for(ll i=1;i<=n;i++)
        dista[i]=dista[i-1]+a[i-1];
    for(ll i=1;i<=n;i++)
        distb[i]=distb[i-1]+b[i-1];
    ll count=0;
    for(ll i=0;i<dista.size()-1;i++)
    {
        if(dista[i]==distb[i] && dista[i+1]==distb[i+1])
            count=count+dista[i+1]-dista[i];
    }
    cout<<count<<endl;   
}
int main() 
{
    fastio
	ll test;
	cin>>test;
	while(test--)
	    solve();
	return 0;
}
