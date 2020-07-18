#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
ll solve()
{
    ll n,r=0,m=0;
    cin>>n;
    string groom,bride;
    cin>>bride;
    cin>>groom;
    for(ll i=0;i<n;i++)
    {
        if(groom[i]=='r') r++;
        else m++;
    }
    for(ll i=0;i<n;i++)
    {
        if(bride[i]=='r')
        {
            if(r>0) r--;
            else return (bride.size()-i);
        }
        else
        {
            if(m>0) m--;
            else return (bride.size()-i);
        }
    }
    return 0;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cout<<solve()<<endl;
	return 0;
}