//https://www.codechef.com/JUNE20A/problems/EOEO
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
bool PowerOfTwocheck(ll x)  
{
    return x && (!(x&(x-1)));  
}
void solve()
{
    ll ts;
    cin>>ts;
    if(ts==1 || PowerOfTwocheck(ts))
    {
        cout<<"0\n";
        return;
    }
    if(ts%2!=0)
    {
        cout<<(ll)ts/2<<endl;
        return;
    }
    else
    {
        ll maxPowerofTwo=0,temp=ts,js;
        while(temp%2==0)
        {
            maxPowerofTwo++;
            temp=temp/2;
        }
        js = 1ll<<(maxPowerofTwo+1);
        cout<<(ll)ts/js<<endl;
    }
}
int main() 
{
    #ifndef ONLINE_JUDGE  
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
    fastio
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}