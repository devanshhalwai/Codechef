#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <cctype>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <functional>
#include <iterator>
#include <random>
#include <utility>
using namespace std;
#define REP(i,n) for(long long int i=0;i<(n);i++)
#define REPD(i,n) for(long long int i=(n);i>=0;i++)
#define FOR(i,a,b) for(long long int i=(a);i<(b);i++)
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
ll getMaxGold(vector<vector<ll>> gold,ll m,ll n)
{  
    vector<vector<ll>> goldTable(n,vector<ll>(m,0));
    for (int col=n-1; col>=0; col--) 
        for (int row=0; row<m; row++) 
            goldTable[row][col] = 0;
    for (ll col=n-1; col>=0; col--) 
    { 
        for (ll row=0; row<m; row++) 
        {
            ll right = (col==n-1)? 0:goldTable[row][col+1]; 
            ll right_up = (row==0 || col==n-1)? 0:goldTable[row-1][col+1]; 
            ll right_down = (row==m-1 || col==n-1)? 0:goldTable[row+1][col+1]; 
            goldTable[row][col] = gold[row][col] + max(right, max(right_up, right_down));                                     
        } 
    }  
    ll res = goldTable[0][0]; 
    for (ll i=1; i<m; i++) 
        res = max(res, goldTable[i][0]); 
    return res; 
}
int main() 
{
    int ans= max(5,2);
    cout<<ans;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<vector<ll>> gold(n,vector<ll>(m,0));
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++)
                cin>>gold[i][j];
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<m;j++)
                cout<<gold[i][j]<<" ";
            cout<<endl;
        }
        cout<<getMaxGold(gold,m,n);
    }
	return 0;
}
