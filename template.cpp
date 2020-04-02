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
//Seive of Eranthoses
vector<bool> prime_arr(int n) 
{
    vector<bool> seive_arr(n+1,true); 
    seive_arr[0]=false;
    seive_arr[1]=false;
    for (ll p=2; p*p<=n; p++) 
    { 
        if(seive_arr[p]) 
        { 
            for (ll i=p*p;i<=n;i+=p) 
                seive_arr[i]=false; 
        } 
    } 
    return seive_arr;
} 
//XOR of 1 to N
ll XOR1toN(const ll n) 
{     
    switch(n & 3)  
    { 
        case 0: return n;     
        case 1: return 1;       
        case 2: return n + 1;  
        case 3: return 0;  
    } 
} 
//----------------------------END OF TEMPLATE---------------------------------//

int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        //your code goes here
    }
	return 0;
}
