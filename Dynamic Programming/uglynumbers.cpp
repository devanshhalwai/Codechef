//https://www.geeksforgeeks.org/ugly-numbers/
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define endl "\n"

void getNthUglyNo(ll n) 
{ 
    ll ugly[n],i2=0,i3=0,i5=0,next_multiple_of_2 = 2,next_multiple_of_3 = 3,next_multiple_of_5 = 5,next_ugly_no=1; 
    ugly[0]=1; 
    for(int i=1;i<n;i++) 
    { 
       next_ugly_no = min(next_multiple_of_2, min(next_multiple_of_3,next_multiple_of_5)); 
       ugly[i] = next_ugly_no; 
       if(next_ugly_no == next_multiple_of_2) 
       { 
            i2 = i2+1; 
            next_multiple_of_2 = ugly[i2]*2; 
       } 
       if (next_ugly_no == next_multiple_of_3) 
       { 
            i3 = i3+1; 
            next_multiple_of_3 = ugly[i3]*3; 
       } 
       if (next_ugly_no == next_multiple_of_5) 
       { 
           i5 = i5+1; 
           next_multiple_of_5 = ugly[i5]*5; 
       } 
    }
    for(ll i=0;i<n;i++)
        cout<<ugly[i]<<" ";
    cout<<endl;
    cout<<"Nth Ugly Number : "<<next_ugly_no<<endl;
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
        ll n;
        cin>>n;
        getNthUglyNo(n);
    }
	return 0;
}
