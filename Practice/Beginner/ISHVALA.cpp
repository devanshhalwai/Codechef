#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int x,y,s;
        cin>>x>>y>>s;
        vector<int> row(x);
        vector<int> col(y);
        for(int i=0;i<x;i++)
            cin>>row[i];
        for(int i=0;i<y;i++)
            cin>>col[i];
        int sr=0,sc=0,ans=0;
        for(int i=0;i<x;i++)
        {
            cout<<"sr : "<<sr<<"row[i] : "<<row[i]<<"ans : "<<ans<<"\n";
            sc=0;
            if(row[i]-sr>=s)
            {
                for(int j=0;j<y;j++)
                {
                    cout<<"\tsc : "<<sc<<"col[j] : "<<col[j]<<"ans : "<<ans<<"\n";
                    if(col[j]-sc>=s)
                        ans+=min((col[j]-sc)/s,(row[i]-sr)/s);
                    sc=col[j];
                }
                if(m-sc>=s)
                    ans+=min((m-sc)/s,(row[i]-sr)/s);
            }
            else
            sr=row[i];
        }
        sc=0;
        if(n-sr>=s)
        {
            for(int j=0;j<y;j++)
                {
                    cout<<"\tsc : "<<sc<<"col[j] : "<<col[j]<<"ans : "<<ans<<"\n";
                    if(col[j]-sc>=s)
                        ans+=min((col[j]-sc)/s,(n-sr)/s);
                    sc=col[j];
                }
                if(m-sc>=s)
                    ans+=min((m-sc)/s,(n-sr)/s);
        }
        cout<<ans<<"\n";
    }
	return 0;
}
