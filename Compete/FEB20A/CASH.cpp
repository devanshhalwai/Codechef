//https://www.codechef.com/FEB20B/problems/CASH
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,k,taken_out=0,i;
        cin>>n>>k;
        cout<<"n : "<<n<<"k : "<<k<<"\n";
        vector<int> a(n+1);
        for(i=1;i<=n;i++)
        {
            cout<<"taken_out : "<<taken_out<<"\n";
            cin>>a[i];
            if(taken_out>=(n-i+1)*(k-1))
                break;
            else if(a[i]>k)
                taken_out+=a[i]-k;
            else
                taken_out+=a[i]%k;
        }
        if(i<n)
        {
            cout<<"out of i loop taken_out : "<<taken_out<<"\n";
            taken_out-=(k-(a[i]%k));
            cout<<"a[i]: "<<a[i]<<"i : "<<i<<"k : "<<k<<"\n";
            cout<<"between i and j loop taken_out : "<<taken_out<<"\n";
        }
        for(int j=i+1;j<=n;j++)
        {
            cout<<"inside j loop taken_out : "<<taken_out<<"\n";
            cin>>a[j];
            taken_out-=(a[j]%k==0)?0:(k-(a[j]%k));
        }
        cout<<"outside j loop taken_out : "<<taken_out<<"\n";
        int remaining_multiple=(int)taken_out/k;
        taken_out-=k*remaining_multiple;
        cout<<"taken_out : "<<taken_out<<"\n";
        cout<<taken_out<<"\n";
    }
    return 0;
}