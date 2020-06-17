//https://www.codechef.com/JUNE20A/problems/DIFVAL
//Reference Link --> https://github.com/anh1l1ator/Spoj/blob/master/Desktop/Codes/DQUERY_Online.cpp
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007
#define mid(L,R) ((L+R)/2)
ll gc = 0,Nn;
ll G[200005];
ll root[200005];
struct queries
{
    ll x,d,ans=0;
};
struct Node
{ 
    ll cnt , L , R;
    Node()
    {
        cnt=0;
        L = R = -1;
    }
    Node(ll x,ll y,ll z)
    {
        L = x;
        R = y;
        cnt = z;
    }
}tree[8160001];
ll build(ll L ,ll R)
{
    ++gc;
    if(L==R)
        return gc;
    ll x = gc;
    tree[x] = Node(build(L,mid(L,R)),build(mid(L,R)+1,R),0);
    return x;
}
ll update(ll L ,ll R ,ll root,ll idx ,ll val)
{
    if(L>idx || R<idx)
        return root;
    ++gc;
    if(L==idx&&R==idx)
    {
        tree[gc] = Node(-1,-1,tree[root].cnt+val);
        return gc;
    }
    ll x = gc;
    tree[x]=Node(update(L,mid(L,R),tree[root].L,idx,val),update(mid(L,R)+1,R,tree[root].R,idx,val),tree[root].cnt+val);
    return x;
}

ll query(ll L ,ll R ,ll root ,ll qe ,ll qr)
{
    if(qr<L || qe>R)return 0;
    if(qe<=L && R<=qr)
        return tree[root].cnt;
    return query(L,mid(L,R),tree[root].L,qe,qr)+
            query(mid(L,R)+1,R,tree[root].R,qe,qr);
}
void dfs_arr(ll u, ll par, ll &cur, vector<ll> &ST, vector<ll> &EN, vector<ll> &ID, vector<vector<ll>> &adj)
{
    ST[u] = ++cur;
    ID[cur] = u;
    for (ll i = 0; i < adj[u].size(); i++)
    {
        ll v = adj[u][i];
        if (v == par)
            continue;
        dfs_arr(v, u, cur, ST, EN, ID, adj);
    }
    EN[u] = ++cur;
    ID[cur] = u;
}
void solve()
{
    gc=0;
    memset(G,-1,sizeof(G));
    ll n, cur = 0;
    cin >> n;
    Nn=n;
    vector<ll> parent(n+1,0),values(n+1,0),ST(n+1,-1),EN(n+1,-1),ID(2*n+1,-1);
    vector<vector<ll>> adj(n + 1);
    bool runSegmentTree=true;
    for (ll i = 2; i < parent.size(); i++)
    {
        cin >> parent[i];
        adj[parent[i]].push_back(i);
        if(parent[i]!=i-1)
            runSegmentTree=false;
    }
    for (ll i = 1; i < values.size(); i++)
        cin >> values[i];
    values[0]=values[1];
    root[0] = build(1,n);
    for(ll i=1;i<=n;++i)
    {
        ll p = root[i-1];
        if(G[values[i]]!=-1)
            p = update(1,n,p,G[values[i]],-1);
        root[i] = update(1,n,p,i,1);
        G[values[i]]=i;
    }
    ll q;
    cin >> q;
    vector<queries> qarr(q);
    if(runSegmentTree)
    {
        for (ll i = 0; i < q; i++)
        {
            cin >> qarr[i].x >> qarr[i].d;
            if (i > 0)
            {
                qarr[i].x ^= qarr[i - 1].ans;
                qarr[i].d ^= qarr[i - 1].ans;
            }
            ll l=qarr[i].x;
            ll r = ((qarr[i].x + qarr[i].d) >= n) ? n : (qarr[i].x + qarr[i].d);
            qarr[i].ans = query(1,n,root[r],l,r);
            cout << qarr[i].ans << endl;
        }
        return;
    }
    dfs_arr(1, -1, cur, ST, EN, ID, adj);
    for (ll i = 0; i < q; i++)
    {
        cin >> qarr[i].x >> qarr[i].d;
        if (i > 0)
        {
            qarr[i].x ^= qarr[i - 1].ans;
            qarr[i].d ^= qarr[i - 1].ans;
        }
        stack<ll> mystack;
        set<ll> myset;
        for (ll j = ST[qarr[i].x]; j <= EN[qarr[i].x]; j++)
        {
            if (!mystack.empty() && mystack.top() == ID[j])
                mystack.pop();
            else
            {
                mystack.push(ID[j]);
                if (mystack.size() - 1 <= qarr[i].d)
                    myset.insert(values[ID[j]]);
            }
        }
        qarr[i].ans = myset.size();
        cout << qarr[i].ans << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}