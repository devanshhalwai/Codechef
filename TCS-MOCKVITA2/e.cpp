#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll solve()
{
    ll n;
    cin>>n;
    vector<ll> ip(n+1,0),calc(n+1,0);
    for(ll i=1;i<=n;i++) cin>>ip[i];
    for(ll i=1;i<=n;i++)
    {
        ll pos=i;
        ll count=0;
        while(ip[pos]!=i)
        {
            pos=ip[pos];
            count++;
        }
        if(count!=0) calc[i]=count+1;
        else calc[i]=count;
    }
    sort(calc.begin(),calc.end());
    ll ans=calc[calc.size()-1];
    for(ll i=2;i<n;i++) if(calc[i]!=0) ans=(((calc[i]*ans))/ (__gcd(calc[i],ans)));
    return ans; 
}
int main() 
{
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        cout<<solve()<<endl;
    return 0;
}