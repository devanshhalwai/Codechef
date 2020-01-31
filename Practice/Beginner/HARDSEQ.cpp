#include<bits/stdc++.h>
using namespace std;
vector<int> arr(129);
vector<int> lastoccurrence(129,-1);
vector<int> secondlastoccurrence(129,-1);
void create()
{
    arr[0]=0;
    arr[1]=0;
    lastoccurrence[0]=1;
    secondlastoccurrence[0]=0;
    for(int i=2;i<=128;i++)
    {
        if(lastoccurrence[arr[i-1]]!=-1 && secondlastoccurrence[arr[i-1]]!=-1)
            arr[i]=lastoccurrence[arr[i-1]]-secondlastoccurrence[arr[i-1]];
        else
            arr[i]=0;
        secondlastoccurrence[arr[i]]=lastoccurrence[arr[i]];
        lastoccurrence[arr[i]]=i;
    }
}
void printvector(vector<int> sample)
{
    cout<<"{";
    for(int i=0;i<sample.size()-1;i++)
        cout<<sample[i]<<" ,";
    cout<<sample[sample.size()-1]<<"}";
    cout<<"\n";
}
int main() 
{
    create();
    printvector(arr);
    int t;
	cin>>t;
	while(t--)
	{
	    int n,ans=0;
	    cin>>n;
	    for(int i=0;i<=n-1;i++)
	        if(arr[i]==arr[n-1])
	            ans++;
	    cout<<ans<<"\n";
	}
	return 0;
}