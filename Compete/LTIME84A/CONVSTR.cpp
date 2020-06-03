//https://www.codechef.com/LTIME84A/problems/CONVSTR
#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define M 500005
#define mod 1000000007
#define inf LLONG_MAX
#define endl "\n"
#define MAX 100000
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,i,j,temp=0;
		cin>>n;
		string a,b;
		cin>>a>>b;
		vector<ll> diff[26];
		for(i=0;i<n;i++){
			if(a[i]<b[i])
				temp=-1;
			if(a[i]!=b[i]){
				diff[b[i]-'a'].push_back(i);
			}
		}
		if(temp==-1)
		{
			cout<<-1<<endl;
			continue;
		}
		ll cnt=0;
		set<ll> ans[n];
		for(i=25;i>=0;i--){
			ll len=diff[i].size();
			ll hs=0;
			if(len){
				cnt++;
				for(j=0;j<n;j++){
					if(a[j]==i+'a')
						hs=j+1;
				}
				if(hs==0){
					cnt=-1;
					break;
				}
				for(j=0;j<len;j++){
					ll pos=diff[i][j];
					a[pos]=i+'a';
					ans[cnt-1].insert(pos);
				}	
				ans[cnt-1].insert(hs-1);
			}
		}
		if(cnt==-1){
			cout<<cnt<<endl;
		}
		else{
			cout<<cnt<<endl;
			for(i=0;i<cnt;i++){
				cout<<ans[i].size()<<" ";
				for(auto val: ans[i])
					cout<<val<<" ";
				cout<<endl;
			}
		}
	}
    return 0;
}