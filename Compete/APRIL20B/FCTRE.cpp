//https://www.codechef.com/APRIL20B/problems/FCTRE
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007
#define sz 1000005
#define pii pair<ll,ll>
vector<ll> logn(sz);
vector<ll> p2(63);
vector<ll> spf(sz); 
ll block;
inline int64_t gilbertOrder(int x, int y, int pow, int rotate) 
{
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}
struct Query 
{ 
    ll L,R,queryno,caseno,ex;
    int64_t ord;
	inline void calcOrder() 
	{
		ord = gilbertOrder(L,R,21,0);
	}
};
inline bool operator<(const Query &a, const Query &b) {
	return a.ord < b.ord;
}
ll invrs[1000006];
ll power(ll x,ll y)
{
    ll res = 1;    
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % MOD;  
        y = y>>1;
        x = (x*x) % MOD;  
    }  
    return res;  
}
void modIn() 
{ 
	ll i;
    invrs[0] =1;
	invrs[1] =1; 
    for(i = 2; i < 1000006; i++)  
        invrs[i]= (invrs[MOD % i]*(MOD - MOD / i))% MOD;     
} 
void sieve() 
{ 
	spf[1] = 1; 
	for (ll i=2; i<sz; i++)  
		spf[i] = i; 
	for (ll i=4; i<sz; i+=2) 
		spf[i] = 2; 
	for (ll i=3; i*i<sz; i++) 
	{  
		if (spf[i] == i) 
		{ 
			for (ll j=i*i; j<sz; j+=i) 
				if (spf[j]==j) 
					spf[j] = i; 
		} 
	} 
} 
void getFactorization(ll pos,ll x,vector<vector<pii> >& product) 
{ 
	priority_queue<ll,vector<ll>,greater<ll> > temp;
	while (x != 1) 
	{ 
		temp.push(spf[x]);
		x = x/spf[x]; 
	} 
	ll val,cur=-1,cnt=0;
	while(!temp.empty())
	{
		val=temp.top();
		temp.pop();
		if(val==cur)
			cnt++;
		else if(cur==-1)
		{
			cur=val;
			cnt=1;	
		}	
		else
		{
			product[pos].push_back({cur,cnt});
			cur=val;
			cnt=1;
		}
		if(temp.empty())
			product[pos].push_back({cur,cnt});
	} 
} 
ll query(vector<vector<ll>>& dp,vector<ll>& depthArr,ll l,ll r) 
{ 
	ll d = r-l; 
	ll dx = logn[d]; 
	if (l==r) return l; 
	if (depthArr[dp[l][dx]] > depthArr[dp[r-p2[dx]][dx]]) 
		return dp[r-p2[dx]][dx]; 
	else
		return dp[l][dx]; 
} 
ll LCA(vector<vector<ll>>& dp,vector<ll>& depthArr,vector<ll>& euler,vector<ll>& FAI,ll u,ll v) 
{  
	if(u==v) 
	return u; 
	if(FAI[u]>FAI[v]) 
	swap(u,v); 
	return euler[query(dp,depthArr,FAI[u], FAI[v])]; 
} 
vector<vector<ll>> buildSparseTable(vector<ll>& depthArr) 
{ 
    ll n=depthArr.size();
    vector<vector<ll>> dp(n+1,vector<ll>(20,-1));
	for (ll i=1; i<n; i++) 
		dp[i-1][0]=(depthArr[i]>depthArr[i-1])?i-1:i; 
	for (ll l=1; l<20; l++)
    { 
        for (ll i=0; i<n; i++)
        { 
            if (dp[i][l-1]!=-1 and dp[i+p2[l-1]][l-1]!=-1) 
            dp[i][l] = (depthArr[dp[i][l-1]]>depthArr[dp[i+p2[l-1]][l-1]])?dp[i+p2[l-1]][l-1] : dp[i][l-1]; 
            else
                break;
        }
    } 
    return dp;
} 
void preprocess() 
{  
	p2[0] = 1; 
	for (ll i=1; i<63; i++) 
		p2[i] = p2[i-1]*2; 
	ll val = 1,ptr=0; 
	for (ll i=1; i<sz; i++) 
	{ 
		logn[i] = ptr-1; 
		if (val==i) 
		{ 
			val*=2; 
			logn[i] = ptr; 
			ptr++; 
		} 
	} 
} 
void dfs(vector<vector<ll>>& adj,vector<ll> &euler,vector<ll> &level,vector<ll> &FAI,ll &ptr,ll cur,ll prev,ll dep) 
{ 
	if (FAI[cur]==-1) 
		FAI[cur] = ptr; 
	level[cur] = dep; 
	euler.push_back(cur); 
	ptr++; 
	for (auto x:adj[cur]) 
	{ 
		if (x != prev) 
		{ 
			dfs(adj,euler,level,FAI,ptr,x,cur,dep+1); 
			euler.push_back(cur); 
			ptr++; 
		} 
	} 
} 
void dfs_arr(ll u, ll par,ll &cur,vector<ll> &ST,vector<ll> &EN,vector<ll> &ID,vector<vector<ll>>& adj)
{
 	ST[u] = ++cur; 
 	ID[cur] = u;
 	for (ll i=0;i<adj[u].size();i++)
    {
 		ll v = adj[u][i];
        if (v == par) 
         continue;
		dfs_arr(v,u,cur,ST,EN,ID,adj);
	}
	EN[u] = ++cur; 
    ID[cur] = u;
}
// bool compare(Query& x, Query& y) 
// { 
//     if (x.L/block != y.L/block) 
//         return x.L/block < y.L/block; 
//     return x.R < y.R; 
// } 
void check(ll x,vector<ll> &currFactor,vector<ll> &VIS, vector<vector<pii>>& housesproduct,ll &ans)
{
    if((VIS[x])==1) 
    {
        for(ll i=0;i<housesproduct[x].size();i++)
        {
            ll val=housesproduct[x][i].first;
            ll cnt=housesproduct[x][i].second;
            if(cnt>0)
            {
                ans =( ((ans*invrs[currFactor[val]+1])%MOD)*((currFactor[val]-cnt+1)%MOD))%MOD;
                currFactor[val] -= cnt;
            }
        }
    } 
    else if(VIS[x]==0) 
    {
        for(ll i=0;i<housesproduct[x].size();i++)
        {
            ll val=housesproduct[x][i].first;
            ll cnt=housesproduct[x][i].second;
            if(cnt>0)
            {
                ans = (((ans*invrs[currFactor[val]+1])%MOD)*((currFactor[val]+cnt+1)%MOD))%MOD;
                currFactor[val] += cnt;
            }
        }
    } 
    VIS[x]^=1;
    
}
void factorquery(vector<ll>& ID,vector<Query> &q_arr, vector<vector<pii>>& housesproduct,vector<ll> &ans,ll nodes)
{ 
    ll n=ID.size();
    block = (ll)sqrt(n); 
    ll m=q_arr.size();
    sort(q_arr.begin(),q_arr.end());
    vector<ll> currFactor(1000005,0);
    ll currL=q_arr[0].L,currR=q_arr[0].L-1;
    vector<ll> VIS(nodes+1,0);
    ll divisors = 1;
    for (ll i=0; i<m; i++) 
    { 
        while (currL < q_arr[i].L) check(ID[currL++], currFactor,VIS,housesproduct,divisors);
		while (currL > q_arr[i].L) check(ID[--currL], currFactor,VIS,housesproduct,divisors);
		while (currR < q_arr[i].R) check(ID[++currR], currFactor,VIS,housesproduct,divisors);
		while (currR > q_arr[i].R) check(ID[currR--], currFactor,VIS,housesproduct,divisors);
        if(q_arr[i].caseno == 2)
        {
            ll tempans=divisors;
            for(ll j=0;j<housesproduct[q_arr[i].ex].size();j++)
            {
            	ll val=housesproduct[q_arr[i].ex][j].first;
            	ll cnt=housesproduct[q_arr[i].ex][j].second;
                tempans = (((tempans*invrs[currFactor[val]+1])%MOD)*((currFactor[val]+cnt+1)%MOD))%MOD;
            }
            tempans=tempans%MOD;
            ans[q_arr[i].queryno]=tempans;
        }
        else
            ans[q_arr[i].queryno]=divisors;
    } 
} 


int main() 
{  
    preprocess();
    sieve();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    modIn();
    while(t--)
    {
        ll n,q,u,v,src,dst,ptr=0,cur=0; // pointer to euler walk 
        cin>>n;
        vector<vector<ll>> adj(n+1),dp; // stores the tree
        vector<ll> houses(n+1),FAI(n+1,-1),euler,level(n+1),depthArr,ST(n+1,-1),EN(n+1,-1),ID(2*n+1,-1);
        vector<vector<pii>> housesproduct(n+1); 
        vector<ll> VIS(n+1,0);
        for(ll i=0;i<n-1;i++)
        {
            cin>>u>>v;
            adj[u].push_back(v); 
	        adj[v].push_back(u);
        }
        for(ll i=1;i<=n;i++)
        {
            cin>>houses[i];
            getFactorization(i,houses[i],housesproduct);
        }
        dfs(adj,euler,level,FAI,ptr,1,0,0); 
        for (auto x : euler) 
		    depthArr.push_back(level[x]);
        dp = buildSparseTable(depthArr);
        dfs_arr(1,-1,cur,ST,EN,ID,adj);
        cin>>q;
        vector<ll> ans(q,0);
        ll j=0;
        vector<Query> q_arr(2*q);
        for(ll i=0;i<q;i++)
        {
            cin>>src>>dst;
            if(src>dst)
            {
                ll temp=src;
                src=dst;
                dst=temp;
            }
            ll mid = LCA(dp,depthArr,euler,FAI,src,dst);
            if(mid == src)
            {
                //[ST(u),ST(v)]
                q_arr[j].queryno=i;
                q_arr[j].L = ST[src];
                q_arr[j].R = ST[dst];
                q_arr[j].caseno = 1;
                q_arr[i].ex = -1;
                q_arr[i].calcOrder();
                j++;
            }
            else
            {
                //[EN(u),ST(v)] + [ST(P),ST(P)].
                q_arr[j].queryno = i;
                q_arr[j].L = EN[src];
                q_arr[j].R = ST[dst];
                q_arr[j].caseno = 2;
                q_arr[i].ex = mid;
                q_arr[i].calcOrder();
                j++;            
            }
        }
        q_arr.resize(j);
        factorquery(ID,q_arr,housesproduct,ans,n);
        for(ll i=0;i<ans.size();i++)
            cout<<ans[i]<<endl;
    }
	return 0;
}
