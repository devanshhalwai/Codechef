//https://www.codechef.com/MAY20B/problems/CHANDF
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll exponentof2[45],test,x,y,l,r,r_arr[45],z_arr[45],l_arr[45],x_arr[45],y_arr[45];
ll binaryconv(ll decimal,ll arr[])
{
    ll i=0;
    while(decimal>0) 
    { 
        arr[i]=decimal%2; 
        decimal/=2; 
        i++; 
    }
}
ll func(ll z)
{
    return ((x&z)*(y&z));
}
void calculatorexponent()
{
    exponentof2[0]=1;
    for(ll i=1;i<45;i++)
        exponentof2[i]=2*exponentof2[i-1];
}
int main()
{
    calculatorexponent();
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>test;
	while(test--)
	{
		ll val=0,maxi=0,ans=0,i;
		cin>>x>>y>>l>>r;
        for(i=0;i<45;i++)
        {
            r_arr[i]=0;
            l_arr[i]=0;
            z_arr[i]=0;
            x_arr[i]=0;
            y_arr[i]=0;
        }
		if((x==0 || y==0))
		{
			cout<<l<<endl;
			continue;
		}
		binaryconv(r,r_arr);
		binaryconv(l,l_arr);
		binaryconv(x,x_arr);
		binaryconv(y,y_arr);
        bool valve=false;
		for(i=44;i>=0;i--)
		{
		    if(r_arr[i]==1)
		    {
		        if(valve==false)
				{
					if(l_arr[i]==0)
					{
						if(func((exponentof2[i]+val-1))>maxi)
						{
							maxi=func((exponentof2[i]+val-1));
							ans=(exponentof2[i]+val-1);
						}
						val+=exponentof2[i];
						if(func(val)>maxi)
						{
							maxi=func(val);
							ans=val;
						}
						valve=true;
					}
					else
					{
						val+=exponentof2[i];
						if(func(val)>maxi)
						{
							maxi=func(val);
							ans=val;
						}
					}
				}
				else
				{
				    if(func((exponentof2[i]+val-1))>maxi)
					{
						maxi=func((exponentof2[i]+val-1));
						ans=(exponentof2[i]+val-1);
					}
					val+=exponentof2[i];
					if(func(val)>maxi)
					{
						maxi=func(val);
						ans=val;
					}
				}
		    }
		}
        binaryconv(ans,z_arr);
		for(i=44;i>=0;i--)
			if(x_arr[i]==0 && y_arr[i]==0 && z_arr[i]==1 && (ans-exponentof2[i])>=l)
				ans-=exponentof2[i];
		if(ans<l)
			cout<<l<<endl;
		else
			cout<<ans<<endl;
	}
    return 0;
}
