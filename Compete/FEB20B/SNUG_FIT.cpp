//https://www.codechef.com/FEB20B/problems/SNUG_FIT
#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n,ans=0;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int> b(n);
        for(int i=0;i<n;i++)
            cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++)
        {
            ans+=min(a[i],b[i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}