#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll bitscore(ll value)
{
    ll a,b,c;
    a=value%10;
    value/=10;
    b=value%10;
    value/=10;
    c=value%10;
    ll max=(a>b)?((a>c)?a:c):((b>c)?b:c);
    ll min=(a<b)?((a<c)?a:c):((b<c)?b:c);
    value = ((max*11)+(min*7));
    value/=10;
    b=value%10;
    return b;
}
ll check(ll a,ll b) {
    if(a>2 || b>2 || (a==2 && b==2)) return 2;
    if(a==2 || b==2) return 1;
    return 0;
}
int main() 
{
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll n,ans=0;
    cin>>n;
    vector<ll> ip(n,0),oddplaces(10,0),evenplaces(10,0);
    for(ll i=0;i<n;i++) {
        cin>>ip[i];
        ip[i]=bitscore(ip[i]);
        if(i%2==0) evenplaces[ip[i]]++;
        else oddplaces[ip[i]]++;
    }
    for(ll i=0;i<10;i++)
        ans+=check(oddplaces[i],evenplaces[i]);
    cout<<ans;
    return 0;
}