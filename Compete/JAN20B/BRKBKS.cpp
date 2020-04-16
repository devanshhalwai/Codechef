//https://www.codechef.com/JAN20B/problems/BRKBKS
#include <iostream>
using namespace std;
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    int i,w[3],s;
	    cin>>s;
	    for(i=0;i<3;i++)
	        cin>>w[i];
	    if(s>=w[0]+w[1]+w[2])
	        cout<<1<<"\n";
	    else if(s>=w[0]+w[1] || s>=w[1]+w[2])
	        cout<<2<<"\n";
	    else
	        cout<<3<<"\n";
	}
	return 0;
}

