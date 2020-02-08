//https://www.codechef.com/FEB20B/problems/NOCHANGE
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        int n,p,fail=0,i;
        cin>>n>>p;
        vector<int> D(n);
        vector<int> C(n,0);
        for(i=0;i<n;i++)
        {
            cin>>D[i];
            if(D[i]>p)
            {
                C[i]=1;
                break;
            }
            if(p%D[i]!=0)
            {
                C[i]=(((int)p/D[i])+1);
                break;
            }
        }
        if(i==n)
            cout<<"NO\n";
        else
        {
            for(int j=i+1;j<n;j++)
                cin>>D[j];
            cout<<"YES ";
            for(int k=0;k<n;k++)
                cout<<C[k]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}