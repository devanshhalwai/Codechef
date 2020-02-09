//https://www.codechef.com/FEB20B/problems/NOCHANGE
#include<bits/stdc++.h>
using namespace std;
void process(long long int D[],long long int n,long long int p)
{
    vector<long long int> C(n,0);
    long long int caluclated_p=p;
    for(long long int i=n-1;i>=0;i--)
    {
        if(D[i]>p)
        {
            vector<long long int> C1(n,0);
            C1[i]=1;
            cout<<"YES";
            for(long long int i=0;i<C1.size();i++)
                cout<<" "<<C1[i];
            cout<<"\n"; 
            return;
        }
        if(p%D[i]!=0)
        {
            vector<long long int> C1(n,0);
            C1[i]=(long long int)(p/D[i])+1;
            cout<<"YES";
            for(long long int i=0;i<C1.size();i++)
                cout<<" "<<C1[i];
            cout<<"\n"; 
            return;
        }
        if(p%D[i]==0 && caluclated_p>0)
        {
            if(caluclated_p%D[i]==0)
            {
                C[i]=(long long int)(caluclated_p/D[i])-1;
                caluclated_p-=D[i]*C[i];
            }
            else
            {
                C[i]=(long long int)(caluclated_p/D[i])+1;
                cout<<"YES";
                for(long long int i=0;i<C.size();i++)
                    cout<<" "<<C[i];
                cout<<"\n"; 
                return;
            }   
        }
    }
    cout<<"NO\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,p;
        cin>>n>>p;
        long long int D[n];
        for(long long int i=0;i<n;i++)
            cin>>D[i];
        process(D,n,p);
    }
    return 0;
}