//https://www.codechef.com/LTIME84A/problems/LOSTWKND
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
    vector<ll> work(5,0);
    for(ll i=0;i<5;i++)
        cin>>work[i];
    ll p,sum=0;
    cin>>p;
    for(ll i=0;i<5;i++)
    {
        work[i]=work[i]*p;
        sum+=work[i];
    }
    if(sum>24*5)
        cout<<"Yes\n";
    else
        cout<<"No\n";
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
