//https://www.codechef.com/JUNE20A/problems/TTUPLE
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
vector<ll> target(3,0),initial(3,0);
ll noofsame=0;
bool case1()
{
    if(target[0]==target[1] && target[0]==0 && initial[2]==target[2])
        return true;
    if(target[0]==target[2] && target[0]==0 && initial[1]==target[1])
        return true;
    if(target[1]==target[2] && target[1]==0 && initial[0]==target[0])
        return true;
    if((initial[2]==target[2] && initial[1]==target[1]) || (initial[0]==target[0] && initial[1]==target[1]) || (initial[0]==target[0] && initial[2]==target[2]))
        return true;
    ll x,y;
    if(initial[0]!=0 && target[0]%initial[0]==0)
    {
        x=target[0]/initial[0];
        if((initial[2]*x==target[2] && initial[1]==target[1]) || (initial[1]*x==target[1] && initial[2]*x==target[2]) || (initial[1]*x==target[1] && initial[2]==target[2]))
            return true;
    }
    if(initial[1]!=0 && target[1]%initial[1]==0)
    {
        x=target[1]/initial[1];
        if((initial[2]*x==target[2] && initial[0]==target[0]) || (initial[0]*x==target[0] && initial[2]*x==target[2]) || (initial[0]*x==target[0] && initial[2]==target[2]))
            return true;
    }
    if(initial[2]!=0 && target[2]%initial[2]==0)
    {
        x=target[2]/initial[2];
        if((initial[1]*x==target[1] && initial[0]==target[0]) || (initial[1]*x==target[1] && initial[0]*x==target[0]) || (initial[0]*x==target[0] && initial[1]==target[1]))
            return true;
    }
    y=target[0]-initial[0];
    if(y==target[1]-initial[1] && y==target[2]-initial[2])
        return true;
    if(initial[2]==target[2] && target[0]-initial[0]==target[1]-initial[1])
        return true;
    if(initial[1]==target[1] && target[0]-initial[0]==target[2]-initial[2])
        return true;
    if(initial[0]==target[0] && target[1]-initial[1]==target[2]-initial[2])
        return true;
    return false;
}

bool case2()
{
    ll x,y;
    if(initial[0]!=initial[1] && (target[0]-target[1])%(initial[0]-initial[1])==0)
    {
        x=(target[0]-target[1])/(initial[0]-initial[1]);
        y=-initial[0]*x+target[0];
        if(initial[0]*x+y==target[0] && initial[1]*x+y==target[1] && initial[2]*x+y==target[2])
            return true;
    }
    if(initial[0]!=initial[2] && (target[0]-target[2])%(initial[0]-initial[2])==0)
    {
        x=(target[0]-target[2])/(initial[0]-initial[2]);
        y=-initial[0]*x+target[0];
        if(initial[0]*x+y==target[0] && initial[1]*x+y==target[1] && initial[2]*x+y==target[2])
            return true;
    }
    if(initial[2]!=initial[1] && (target[1]-target[2])%(initial[1]-initial[2])==0)
    {
        x=(target[1]-target[2])/(initial[1]-initial[2]);
        y=-initial[1]*x+target[1];
        if(initial[0]*x+y==target[0] && initial[1]*x+y==target[1] && initial[2]*x+y==target[2])
            return true;
    }
    if(target[0]==target[1] && target[0]==target[2] && target[1]==target[2])
        return true;
    if((initial[0]==initial[1] && target[0]==target[1]) || (initial[0]==initial[2] && target[0]==target[2]) || (initial[1]==initial[2] && target[1]==target[2]))
        return true;
    if((target[0]==0 && target[1]==target[2]) || (target[1]==0 && target[0]==target[2]) || (target[2]==0 && target[0]==target[1]))
        return true;
    if(initial[0]!=0 && target[0]%initial[0]==0)
    {
        x=target[0]/initial[0];
        ll u=target[2]-initial[2];
        ll v=target[1]-initial[1];
        if((target[1]-initial[1]*x==target[2]-initial[2]*x) || (initial[2]*x==target[2]) || (initial[1]*x==target[1]) || (initial[1]*x+u==target[1]) || (initial[2]*x+v==target[2]) || ((initial[1]+u)*x==target[1]) || ((initial[2]+v)*x==target[2]))
            return true;
        if(x!=0 && target[1]%x==0 && target[2]%x==0)
            if((target[1]/x)-initial[1]==(target[2]/x)-initial[2])
                return true;
    }
    if(initial[1]!=0 && target[1]%initial[1]==0)
    {
        x=target[1]/initial[1];
        ll u=target[2]-initial[2];
        ll v=target[0]-initial[0];
        if((target[0]-initial[0]*x==target[2]-initial[2]*x) || (initial[0]*x==target[0]) || (initial[2]*x==target[2]) || (initial[0]*x+u==target[0]) || (initial[2]*x+v==target[2]) || ((initial[0]+u)*x==target[0]) || ((initial[2]+v)*x==target[2]))
            return true;
        if(x!=0 && target[0]%x==0 && target[2]%x==0)
            if((target[0]/x)-initial[0]==(target[2]/x)-initial[2])
                return true;
    }
    if(initial[2]!=0 && target[2]%initial[2]==0)
    {
        x=target[2]/initial[2];
        ll u=target[1]-initial[1];
        ll v=target[0]-initial[0];
        if((target[0]-initial[0]*x==target[1]-initial[1]*x) || (initial[0]*x==target[0]) || (initial[1]*x==target[1]) || (initial[0]*x+u==target[0]) || (initial[1]*x+v==target[1]) || ((initial[0]+u)*x==target[0]) || ((initial[1]+v)*x==target[1]))
            return true;
        if(x!=0 && target[0]%x==0 && target[1]%x==0)
            if((target[0]/x)-initial[0]==(target[1]/x)-initial[1])
                return true; 
    }
    if((initial[0]==target[0]) || (initial[1]==target[1]) || (initial[2]==target[2]))
        return true;
    if((target[1]-initial[1]==target[2]-initial[2]) || (target[1]-initial[1]==target[0]-initial[0]) || (target[2]-initial[2]==target[0]-initial[0]))
        return true;
    if((target[1]-initial[1]+target[2]-initial[2]+initial[0]==target[0]) || (target[0]-initial[0]+target[2]-initial[2]+initial[1]==target[1]) || (target[0]-initial[0]+target[1]-initial[1]+initial[2]==target[2]))
        return true;
    if((target[0]==0 && target[1]==0) || (target[0]==0 && target[2]==0) || (target[1]==0 && target[2]==0) || (target[0]==target[2] && target[1]==target[2] && target[2]==target[0]))
        return true;
    if(initial[0]!=0 && initial[1]!=0)
    {
        y=target[2]-initial[2];
        if((target[1]-y)%initial[1]==0 && (target[0]-y)%initial[0]==0)
        {
            ll q2=(target[1]-y)/initial[1];
            ll q3=(target[0]-y)/initial[0];
            if(q2==q3)
                return true;
        }
    }
    if(initial[0]!=0 && initial[2]!=0)
    {
        y=target[1]-initial[1];
        if((target[2]-y)%initial[2]==0 && (target[0]-y)%initial[0]==0)
        {
            ll q2=(target[2]-y)/initial[2];
            ll q3=(target[0]-y)/initial[0];
            if(q2==q3)
                return true;
        }
    }
    if(initial[1]!=0 && initial[2]!=0)
    {
        y=target[0]-initial[0];
        if((target[1]-y)%initial[1]==0 && (target[2]-y)%initial[2]==0)
        {
            ll q2=(target[2]-y)/initial[2];
            ll q3=(target[1]-y)/initial[1];
            if(q2==q3)
                return true;
        }
    }
    y=target[2]-initial[2];
    if((initial[0]+y)!=0 && (initial[1]+y)!=0 && target[0]%(initial[0]+y)==0 && target[1]%(initial[1]+y)==0)
    {
        if(target[0]/(initial[0]+y)==target[1]/(initial[1]+y))
            return true;
    }
    y=target[1]-initial[1];
    if((initial[0]+y)!=0 && (initial[2]+y)!=0 && target[0]%(initial[0]+y)==0 && target[2]%(initial[2]+y)==0)
    {
        if(target[0]/(initial[0]+y)==target[2]/(initial[2]+y))
            return true;
    }
    y=target[0]-initial[0];
    if((initial[2]+y)!=0 && (initial[1]+y)!=0 && target[2]%(initial[2]+y)==0 && target[1]%(initial[1]+y)==0)
    {
        if(target[2]/(initial[2]+y)==target[1]/(initial[1]+y))
            return true;
    }
    if(initial[1]!=0 && target[1]%initial[1]==0 && initial[2]!=0 && target[2]%initial[2]==0)//initial[1],initial[2]
    {
        x=target[1]/initial[1];
        ll q2=target[2]/initial[2];
        if(initial[0]*x*q2==target[0])
            return true;
    }
    if(initial[0]!=0 && target[0]%initial[0]==0 && initial[2]!=0 && target[2]%initial[2]==0)//initial[0],initial[2]
    {
        x=target[0]/initial[0];
        ll q2=target[2]/initial[2];
        if(initial[1]*x*q2==target[1])
            return true;
    }
    if(initial[0]!=0 && target[0]%initial[0]==0 && initial[1]!=0 && target[1]%initial[1]==0)//initial[0],initial[1]
    {
        x=target[0]/initial[0];
        ll q2=target[1]/initial[1];
        if(initial[2]*x*q2==target[2])
            return true;
    }
    return false;
}

void solve()
{
    noofsame=0;
    for(ll i=0;i<3;i++)
        cin>>initial[i];
    for(ll i=0;i<3;i++)
    {
        cin>>target[i];
        if(target[i]-initial[i]==0)
            noofsame++;
    }
    if(noofsame==3)
        cout<<"0\n";
    else if(case1())
        cout<<"1\n";
    else if(case2())
        cout<<"2\n";
    else
        cout<<"3\n";
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll y;
    cin>>y;
    while(y--)
        solve();
    return 0;
}