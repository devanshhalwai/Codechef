//https://www.codechef.com/APRIL20B/problems/ANSLEAK
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007
ll max(ll a,ll b)
{
    return (a>b)?a:b;
}
ll min(ll a,ll b)
{
    return (a>b)?b:a;
}
void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans[n];
    for(ll i=0;i<n;i++)
        ans[i]=0;
    ll iterator = 0;
    for(ll i=0;i<n;i++)
    {
        ll mymap[10];
        for(ll j=0;j<10;j++)
            mymap[j]=0;
        ll maxmpossible=0;
        ll maxmpos=0;
        for(ll j=0;j<k;j++)
        {
            ll temp;
            cin>>temp;
            mymap[temp]++;
            if(mymap[temp]>maxmpossible)
            {
                maxmpossible=mymap[temp];
                maxmpos=temp;
            }
        }
        ans[i] = (maxmpossible==k)?maxmpos:((iterator++)%min(m,6))+1;
    }
    for(auto i:ans)
        cout<<i<<" ";
    cout<<endl;
    
    
    
}

int main() 
{
    srand(time(0));
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
