//https://www.codechef.com/JAN20B/problems/DFMTRX
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    vector<vector<int>> dft(2001,vector<int>(2001));
    cin>>t;
    while(t--)
    {
		int n;
        cin>>n;
        if(n==1)
            cout<<"Hooray\n1\n";
        else if(n%2)
            cout<<"Boo\n";
		else
		{
		    for(int i=1;i<=n;i++)
			{
		        dft[i][i]=n;
		        if(n+1-i>i)
		            dft[i][n+1-i]=n-1;
		        else
		            dft[i][n+1-i]=2*n-1;
		    }
		    for(int i=1;i<=n/2;i++)
		    {
		        int val=2*i-1;
		        for(int j=i+1;j+i<=n;j++)
		        {
		            dft[i][j]=val;
		            val++;
		        }
		    }
		    for(int i=n/2+1;i<=n;i++)
		    {
		        int val=2*n-2;
		        for(int j=n-i+2;j<i;j++)
		        {
		            dft[i][j]=val;
		            val--;
		        }
		    }
		    int val=2*n-3;
		    for(int i=2;i<=n/2;i++)
		    {
		        dft[i][1]=val;
		        dft[i+n/2-1][1]=val+1;
		        val=val-2;
		    }
		    val=2;
		    for(int i=2;i<=n/2;i++)
		    {
		        dft[i][n]=val;
		        dft[i+n/2-1][n]=val-1;
		        val=val+2;
		    }
		    for(int j=2;j<=n/2;j++)
		    {
		        val=2*(n-j);
		        for(int i=j+1;i<=n-j;i++)
		        {
		            dft[i][j]=val;
		            val--;
		        }
		    }
		    for(int j=n/2+1;j<n;j++)
		    {
		        val=1;
		        for(int i=n-j+2;i<j;i++)
		        {
		            dft[i][j]=val;
		            val++;
		        }
		    }
			cout<<"Hooray\n";
        	for(int i=1;i<=n;i++)
            {
            	for(int j=1;j<=n;j++)
                {
                	cout<<dft[i][j]<<" ";
                }
                cout<<"\n";
            }
		}
    }
	return 0;
}
