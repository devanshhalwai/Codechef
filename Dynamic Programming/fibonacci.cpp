///https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
//https://www.geeksforgeeks.org/tiling-problem/
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
#define max(a,b) ((a)>(b))?a:b
#define min(a,b) ((a)<(b))?a:b
#define ll long long int
#define endl "\n"
#define MOD 1000000007
void fibonacci(ll n)
{
    vector<ll> arr(n);
    arr[0]=0;
    arr[1]=1;
    for(ll i=2;i<n;i++)
        arr[i]=arr[i-1]+arr[i-2];
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        fibonacci(n);
    }
	return 0;
}
