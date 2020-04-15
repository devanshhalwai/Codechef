//https://www.codechef.com/APRIL20B/problems/SQRDSUB
#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() 
{
	 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,count=0,temp;
        cin>>n;
        vector<ll> ip(n);
        for(ll i=0;i<n;i++)
        {
            cin>>temp;
            ip[i]=abs(temp)%100;
        }
        ll lmax[n];
        ll rmin[n];
        ll maxi=0,mini=n-1;
        for(ll i=0;i<n;++i)
        {
            lmax[i]=maxi;
            if(ip[i]%2==0)
               maxi=i;
        }
        for(ll i=n-1;i>=0;--i)
        {
            rmin[i]=mini;
            if(ip[i]%2==0)
               mini=i;
        }
        lmax[0]=0;
        rmin[n-1]=0;
        for(ll i=0;i<n;++i)
        {
           if(ip[i]%4==2)
           {
               ll lcount,rcount;
               if(i!=0 && lmax[i]==0 && ip[0]%2)
                  lcount=i-lmax[i];
               else
                  lcount=i-lmax[i]-1;
                  
               if(i!=n-1 && rmin[i]==n-1 && ip[n-1]%2)
                  rcount=rmin[i]-i;
               else
                  rcount=rmin[i]-i-1;
               if(i==0)
                  lcount=0;
               if(i==n-1)
                  rcount=0;
               if(!lcount && !rcount)
                  count+=1;
               else if(!lcount && rcount)
                  count+=rcount+1;
               else if(lcount && !rcount)
                  count+=lcount+1;
               else if(lcount && rcount)
                  count+=lcount*rcount+lcount+rcount+1;
           }
        }
        ll res=(n*(n+1))/2;
        cout<<res-count<<endl;
    }
    
	return 0;
}
