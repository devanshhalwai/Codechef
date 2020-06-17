//https://www.codechef.com/JUNE20A/problems/EVENM
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
    ll n;
    cin>>n;
    vector<vector<ll>> mat(n,vector<ll> (n,0));
    ll val=1;
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
        {
            mat[i][j]=val;
            val++;
        }
    }
    if(n%2!=0)
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
    else
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j+=2)
            {
                if(i%2!=0)
                {
                    ll temp=mat[i][j];
                    mat[i][j]=mat[i][j+1];
                    mat[i][j+1]=temp;
                }
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
    }
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
