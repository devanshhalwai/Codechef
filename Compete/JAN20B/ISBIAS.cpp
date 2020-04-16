//https://www.codechef.com/JAN20B/problems/ISBIAS
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;
void printarr(long long int arr[],int n)
{
    for(int i=1;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}
int main() 
{
	long long int n,q,icount=0,dcount=0,peaks=0,*cum;
	cin>>n>>q;
	vector<int> arr(n+1);
	arr[0]=0;
	cum = (long long int*)calloc(n+1,sizeof(long long int));
	cin>>arr[1];
	for(int i=2;i<=n;i++)
	{
	    cin>>arr[i];
	    if(arr[i]>arr[i-1])
	    {
	        icount++;
	        if(dcount>0)
	        {
	            peaks++;
	            dcount=0;
	        }
	    }
	    else if(arr[i]<arr[i-1])
	    {
	        dcount++;
	        if(icount>0)
	        {
	            peaks++;
	            icount=0;
	        }
	            
	    }
	    cum[i]=peaks;
	}
	//printarr(cum,n+1);
	for(int i=1;i<=q;i++)
	{
	    long long int l,r;
	    cin>>l>>r;
	    if(peaks==0 || r-l<1)
	        cout<<"NO\n";
	    else
	    {
	        if(cum[l+1]-cum[l]==1)
	        {
	            if((cum[r]-cum[l]-1)%2!=0)
	                cout<<"YES\n";
	            else
	                cout<<"NO\n";
	        }
	        else
	        {
	            if((cum[r]-cum[l])%2!=0)
	                cout<<"YES\n";
	            else
	                cout<<"NO\n";
	        }
	    }
	}
	return 0;
}
