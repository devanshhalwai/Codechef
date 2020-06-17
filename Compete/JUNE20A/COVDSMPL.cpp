//https://www.codechef.com/JUNE20A/problems/COVDSMPL
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007
void solve()
{
    ll n, p, x,total;
    scanf("%lld%lld",&n,&p);
    fflush(stdout);
    vector<vector<ll>> mat(n, vector<ll>(n, 0));
    printf("1 %lld %lld %lld %lld\n",1,1,n,n);
    fflush(stdout);
    scanf("%lld",&total);
    fflush(stdout);
    if(total==-1)
        exit(0);
    if(total>0)
    {
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                printf("1 %lld %lld %lld %lld\n",i+1,j+1,i+1,j+1);
                fflush(stdout);
                scanf("%lld",&x);
                fflush(stdout);
                if(x==-1)
                    exit(0);
                mat[i][j] = x;
            }
        }
    }
    printf("2\n");
    for(ll i=0;i<n;i++)
    {
        for(ll j=0;j<n;j++)
            printf("%lld ",mat[i][j]);
        printf("\n");
    }
    fflush(stdout);
}
int main()
{
    ll t,x;
    scanf("%lld",&t);
    while(t--)
    {
        fflush(stdout);
        solve();
        scanf("%lld",&x);
        if(x==-1)
            exit(0);
    }
    return 0;
}