//https://www.codechef.com/JUNE20A/problems/GUESSG
#include <bits/stdc++.h>
#include <stack>
#include <stdio.h>
#include <iostream>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
using namespace std;
void solve(ll N)
{
    ll x,fl=1,fr=N;
	queue<pii> bounds;
	char v1,v2;
	bounds.push({fl,fr});
	while(!bounds.empty())
	{
		ll l=bounds.front().ff;
		ll r=bounds.front().ss;
		bounds.pop();
		while(l<=r && l>=fl && l<=fr && r>=fl && r<=fr)
		{
			x=l+((r-l)/2);
			printf("%lld\n",x);
			fflush(stdout);
			cin>>v1;
			if(v1=='E')
				exit(0);
			fflush(stdout);
			printf("%lld\n",x);
			fflush(stdout);
			cin>>v2;
			fflush(stdout);
			if(v1==v2)
			{
			    while(!bounds.empty())
			        bounds.pop();
				if(v1=='G' && (x+1)<=fr)
				{
					fl=x+1;
					l=x+1;
				}
				if(v1=='L' && (x-1)>=fl)
				{
					r=x-1;
					fr=x-1;
				}
				bounds.push({fl,fr});
				break;
			}
			else
			{
				if(l>=fl && l<=fr && (x-1)>=fl && (x-1)<=fr)
					bounds.push({l,x-1});
				if((x+1)>=fl && (x+1)<=fr && r>=fl && r<=fr)
					bounds.push({x+1,r});
				break;
			}			
		}
	}
}
int main() 
{
    ll N;
    cin>>N;
	fflush(stdout);
    solve(N);
	fflush(stdout);
    return 0;
}