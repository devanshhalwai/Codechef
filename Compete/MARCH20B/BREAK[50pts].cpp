//https://www.codechef.com/MARCH20B/problems/BREAK
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define endl "\n"
void solve1(ll t)
{
	while(t--)
    {
       	ll n,i;
       	cin>>n;
       	vector<ll> a(n),d(n);
		map<ll,ll> ontable;
       	for(i=0;i<n;i++)
		   cin>>a[i];
		for(i=0;i<n;i++)
		   cin>>d[i];
		sort(a.begin(),a.end());
		sort(d.begin(),d.end());
		for(i=0;i<n;i++)
		{
			if(a[i]>=d[i] || (i!=0 && ontable[a[i]]==0))
			{
				cout<<"NO\n";
				break;
			}
			ontable[a[i]]++;
			ontable[d[i]]++;
		}
		if(i==n)
			cout<<"YES\n";
    }
}
void solve2(ll t)
{
	while(t--)
    {
       	ll n,i;
       	cin>>n;
       	vector<ll> a(n),d(n);
		unordered_map<ll,ll> ontable;
       	for(i=0;i<n;i++)
		   cin>>a[i];
		for(i=0;i<n;i++)
		   cin>>d[i];
		sort(a.begin(),a.end());
		sort(d.begin(),d.end());
		for(i=0;i<n;i++)
		{
			if(a.size()==0 || d.size()==0)
			{
				cout<<"YES\n";
				break;
			}
			if(i!=0 && ontable[a[i]]==0)
			{
				ontable.clear();
				vector<ll> c;
				c=a;
				a.clear();
				a=d;
				d.clear();
				d=c;
				if(a.size()==0 || d.size()==0)
				{
					cout<<"YES\n";
					break;
				}
				continue;
			}
			if(a[i]>=d[i])
			{
				for (auto x : ontable)
					d.insert(d.end(),x.second,x.first);
				ontable.clear();
				sort(d.begin(),d.end());
				continue;
			}
			ontable[a[i]]++;
			a.erase(a.begin());
			ontable[d[i]]++;
			d.erase(d.begin());
		}
		if(i==n)
			cout<<"NO\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t,s;
    cin>>t>>s;
    if(s==1)
		solve1(t);
	else
		solve2(t);
	return 0;
}