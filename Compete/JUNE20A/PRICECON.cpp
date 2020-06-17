//https://www.codechef.com/JUNE20A/problems/PRICECON
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
    ll n,k,ans=0,val;
    cin>>n>>k;
    for(ll i=0;i<n;i++)
    {
        cin>>val;
        ans+=(val>k)?(val-k):0;
    }
    cout<<ans<<endl;
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
