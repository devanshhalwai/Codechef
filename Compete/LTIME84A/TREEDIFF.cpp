//https://www.codechef.com/LTIME84B/problems/TREDIFF
#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define M 500005
#define mod 1000000007
#define inf LLONG_MAX
#define endl "\n"
#define MAX 100000
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
vector<ll> lst[200005];
ll cnt[200005][101];
ll a[200005],dp[200005][21],vis[200005],level[200005];
void init(ll n){
	ll i;
	for(i=0;i<=n;i++){
		lst[i].clear();
		a[i]=0;
		vis[i]=0;
		level[i]=0;
		for(ll j=0;j<101;j++)
			cnt[i][j]=0;
		for(ll j=0;j<21;j++)
			dp[i][j]=0;
	}
}
ll dfs(ll x,ll p){
	vis[x]=1;
	dp[x][0]=p;
	level[x]=level[p]+1;
	cnt[x][a[x]]=1;
	for(ll i=1;i<=20;i++)
		dp[x][i]=dp[dp[x][i-1]][i-1];
	for(ll j=0;j<=100;j++)
		cnt[x][j]=cnt[x][j]+cnt[p][j];
	for(ll i=0;i<lst[x].size();i++){
		ll to=lst[x][i];
		if(vis[to]==0){
			dfs(to,x);
		}
	}
}
ll lca(ll x,ll y){
	if(level[x]>level[y])
		swap(x,y);
	ll i;
	ll diff=level[y]-level[x];
	for(i=0;i<21;i++){
		if((1ll<<i)&diff)
			y=dp[y][i];
	}
	if(x==y)
		return x;
	for(i=20;i>=0;i--){
		if(dp[x][i]!=dp[y][i])
		{
			x=dp[x][i];
			y=dp[y][i];
		}
	}
	return dp[x][0];
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		ll i;
		init(n);
		for(i=1;i<=n;i++)
			cin>>a[i];
		ll u,v;
		for(i=0;i<n-1;i++){
			cin>>u>>v;
			lst[u].push_back(v);
			lst[v].push_back(u);
		}
		dfs(1,0);
		while(q--){
			cin>>u>>v;
			ll x,val;
			x=lca(u,v);
			vector<ll> temp;
			ll mini=100000000;
			for(i=1;i<=100;i++){
				ll val=cnt[u][i]+cnt[v][i]-cnt[x][i]-cnt[x][i]+(a[x]==i);
				if(val>1)
					mini=0;
				if(val>0)
					temp.push_back(i);
			}
			for(i=1;i<temp.size();i++){
				mini=min(mini,temp[i]-temp[i-1]);
			}
			cout<<mini<<endl;
		}
	}
    return 0;
}