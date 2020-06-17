//https://www.codechef.com/JUNE20A/problems/CHFICRM
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
    ll n,coin5count=0,coin10count=0,coin15count=0;
    cin>>n;
    vector<ll> val(n);
    for(ll i=0;i<n;i++)
        cin>>val[i];
    for(ll i=0;i<n;i++)
    {
        if(val[i]==5)
        {
            ++coin5count;
        }
        else if(val[i]==10)
        {
            if(coin5count<1)
            {
                cout<<"NO\n";
                return;
            }
            coin5count--;
            coin10count++;
        }
        else if(val[i]==15)
        {
            if(coin10count<1 && coin5count<2)
            {
                cout<<"NO\n";
                return;
            }
            if(coin10count>0)
                coin10count--;
            else if(coin5count>1)
                coin5count=coin5count-2;
        }
    }
    cout<<"YES\n";
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
