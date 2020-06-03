//https://www.codechef.com/MAY20B/problems/TRPLSRT
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
void print(vector<vector<ll>> ansstore,ll k,ll flag)
{
    if(flag==0)
        cout<<"-1"<<endl;
    else
    {
        cout<<k<<endl;
        for(ll i=0;i<ansstore.size();++i)
        {
            for(ll j=0;j<ansstore[i].size();++j)
                cout<<ansstore[i][j]<<" ";
            cout<<endl;
        }
    }
}
void solve()
{
    ll n,k,kitnaklaga=0,kitnasorted=0,kuchbhi=0,valve=1,i;
    cin>>n>>k;
    vector<ll> ip(n+1),dikkat(n+1,0);
    vector<vector<ll>> ansstore;
    for(i=1;i<=n;i++)
        cin>>ip[i];
    for(i=1;i<=n;i++)
    {
        if(i==ip[i])
            ++kitnasorted;
        else if(i==ip[ip[i]])
        {
            ++kuchbhi;
            dikkat[i]=1;
        }
    }
    if(kitnasorted==n)
    {
        print(ansstore,kitnaklaga,valve);
        return;
    }
    i=1;
    while(valve==1 && i<=n)
    {
        if(kitnasorted==n)
            break;
        else if(kuchbhi==2 && kitnasorted==n-2)
        {
            valve=0;
            break;
        }
        else if(i==ip[i])
            i++;
        else if(dikkat[i] && kuchbhi!=n-kitnasorted)
            ++i;
        else
        {
            if(!dikkat[i])
            {
                ll a=i;
                ll b=ip[i];
                ll c=ip[ip[i]];
                ansstore.push_back({a,b,c});
                ll temp=ip[a];
                ip[a]=ip[c];
                ip[c]=ip[b];
                ip[b]=temp;
                ++kitnaklaga;
                if(ip[a]==a)
                    ++kitnasorted;
                if(ip[b]==b)
                    ++kitnasorted;
                if(ip[c]==c)
                    ++kitnasorted;
                if(a==ip[ip[a]] && a!=ip[a])
                {
                    kuchbhi+=2;
                    dikkat[a]=1;
                    dikkat[ip[a]]=1;
                }
                if(b==ip[ip[b]] && b!=ip[b])
                {
                    kuchbhi+=2;
                    dikkat[b]=1;
                    dikkat[ip[b]]=1;
                }
                if(c==ip[ip[c]] && c!=ip[c])
                {
                    kuchbhi+=2;
                    dikkat[c]=1;
                    dikkat[ip[c]]=1;
                }
            }
            if(kuchbhi==2 && kitnasorted==n-2)
            {
                valve=0;
                break;
            }
            if(kuchbhi && kuchbhi==n-kitnasorted)
            {
                ll j=1,maxi,mini,a,b,c;
                while(j<=n)
                {
                    if(dikkat[j]==1)
                    {
                        a=j;
                        break;
                    }
                    ++j;
                }
                b=ip[j];
                j=a+1;
                while(j<=n)
                {
                    if(dikkat[j]==1 && j!=b)
                    {
                        c=ip[j];
                        break;
                    }
                    ++j;
                }
                i=a;
                dikkat[a]=0;
                dikkat[ip[a]]=0;
                dikkat[b]=0;
                dikkat[ip[b]]=0;
                dikkat[c]=0;
                dikkat[ip[c]]=0;
                kuchbhi-=4;
                ansstore.push_back({a,b,c});
                ll temp=ip[a];
                ip[a]=ip[c];
                ip[c]=ip[b];
                ip[b]=temp;
                ++kitnaklaga;
                if(ip[a]==a)
                    ++kitnasorted;
                if(ip[b]==b)
                    ++kitnasorted;
                if(ip[c]==c)
                    ++kitnasorted;
            }
            if(kitnaklaga>k)
                valve=0;
        }
    }
    if(kitnaklaga>k)
        valve=0;
    print(ansstore,kitnaklaga,valve);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}