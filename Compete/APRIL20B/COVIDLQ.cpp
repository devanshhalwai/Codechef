//https://www.codechef.com/APRIL20B/problems/COVIDLQ
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
        ll n,prev_pos=-1,curr_pos=-1;
        bool flag=true;
        cin>>n;
        for(ll i=0;i<n;i++)
        {
            int status;
            cin>>status;
            if(status==1 && flag==true)
            {
                if(prev_pos==-1)
                    prev_pos=i;
                else
                {
                    curr_pos=i;
                    if(curr_pos-prev_pos>=6)
                        prev_pos=curr_pos;
                    else
                        flag=false;
                }
            }
        }
        if(flag)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
	return 0;
}

