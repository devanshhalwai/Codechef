//https://www.codechef.com/APRIL20B/problems/UNITGCD
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define MOD 1000000007

int main() 
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==1)
        {
            cout<<"1\n1 1\n";
        }
        else if(n%2==0)
        {
            cout<<n/2<<"\n";
            for(ll i=1;i<=n;i+=2)
                cout<<"2 "<<i<<" "<<i+1<<"\n";
        }
        else
        {
            cout<<n/2<<"\n";
            cout<<"3 1 2 "<<n<<"\n";
            for(ll i=3;i<=(n-1);i+=2)
                cout<<"2 "<<i<<" "<<i+1<<"\n";
        }

    }
	return 0;
}

