//https://www.codechef.com/JUNE20A/problems/XYSTR
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
    ll pairs=0;
    string s;
    cin>>s;
    for(ll i=0;i<s.size();)
    {
        if((s[i]=='x' && s[i+1]=='y') || (s[i]=='y' && s[i+1]=='x'))
        {
            i+=2;
            pairs++;
        }
        else
            i++;
    }
    cout<<pairs<<endl;
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
