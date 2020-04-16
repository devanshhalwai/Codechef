//https://www.codechef.com/JAN20B/problems/DYNAMO
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	// your code goes here
	int t,n,f;
	long long int a,b,c,d,e,s,p;
	cin>>t;
	while(t--)
	{
	    cin>>n>>a;
	    p=pow(10,n);
	    s=2*p+a;
	    cout<<s<<endl;
	    fflush(stdout);
	    cin>>b;
	    cout<<p-b<<endl;
	    fflush(stdout);
	    cin>>d;
	    cout<<p-d<<endl;
	    fflush(stdout);
	    cin>>f;
	    if(f==-1)
	        exit(0);
	}
	return 0;
}
