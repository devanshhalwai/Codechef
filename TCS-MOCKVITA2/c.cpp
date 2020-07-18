#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll max(ll a,ll b) { return (a>b)?a:b; }
ll min(ll a,ll b) { return (a>b)?b:a; }
void swap(ll &a,ll &b)
{
    ll temp=a;
    a=b;
    b=temp;
}
ll solve(ll l,ll b)
{
    if(b>l) swap(b,l);
    if(l==0 || b==0) return 0;
    if(l==1 || b==1) return l;
    if(l%b==0) return l/b;
    else return ((l-(l%b))/b)+solve(l%b,b);
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll p,q,r,s,ans=0;
    cin>>p>>q>>r>>s;
    for(ll i=p;i<=q;i++)
        for(ll j=r;j<=s;j++)
            ans+=solve(i,j);
    cout<<ans;
    return 0;
}