//https://www.codechef.com/MARCH20B/problems/ENGXOR
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define endl "\n"
bool getParity(unsigned int n) 
{
    bool parity = 0; 
    while (n) 
    { 
        parity = !parity; 
        n = n & (n - 1); 
    }      
    return parity; 
} 
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q,temp,no_of_odd=0,no_of_even=0,p;
        cin>>n>>q;
        for(ll i=0;i<n;i++)
        {
            cin>>temp;
            getParity(temp)?no_of_odd++:no_of_even++;
        }
        for(ll i=0;i<q;i++)
        {
            cin>>p;
            if(getParity(p))
                cout<<no_of_odd<<" "<<no_of_even<<"\n";
            else
                cout<<no_of_even<<" "<<no_of_odd<<"\n";             
        }
    }
	return 0;
}
  
