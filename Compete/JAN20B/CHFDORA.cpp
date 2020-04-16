//https://www.codechef.com/JAN20B/problems/CHFDORA
#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
	    cin>>n>>m;
	    vector<vector<int>> mat(n,vector<int>(m));
	    int ans=n*m;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++)
	            cin>>mat[i][j];
	    for(int i=1;i<n-1;i++)
	    {
	        for(int j=1;j<m-1;j++)
	        {
	            int plus_length=min(min(i,n-1-i),min(j,m-1-j));
	            for(int k=1;k<=plus_length;k++)
	            {
	                if(mat[i][j+k]==mat[i][j-k] && mat[i+k][j] == mat[i-k][j])
	                	ans++;
	                else
	                    break;
	            }
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}

