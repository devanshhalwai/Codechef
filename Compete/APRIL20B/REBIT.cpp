//https://www.codechef.com/APRIL20B/problems/REBIT
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define MOD 998244353
ll power(ll x,ll y)
{
    ll res = 1;    
    while (y > 0)  
    {  
        if (y & 1)  
            res = (res*x) % MOD;  
        y = y>>1;
        x = (x*x) % MOD;  
    }  
    return res;  
}
vector<ll> and_operator(ll exp10,ll exp11,ll exp1a,ll exp1A,ll exp20,ll exp21,ll exp2a,ll exp2A)
{
    vector<ll> count(4,0);
    //for 0
    count[0] += (exp10*exp21)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp10*exp20)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp11*exp20)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp10*exp2a)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp1a*exp20)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp1A*exp20)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp10*exp2A)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp1A*exp2a)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp1a*exp2A)%MOD;
    count[0] = count[0]%MOD;
    
    //for 1
    count[1] += (exp11*exp21)%MOD;
    count[1] = count[1]%MOD;
    //for a
    count[2] += (exp1a*exp21)%MOD;
    count[2] = count[2]%MOD;
    count[2] += (exp11*exp2a)%MOD;
    count[2] = count[2]%MOD;
    count[2] += (exp1a*exp2a)%MOD;
    count[2] = count[2]%MOD;
    // for A
    count[3] += (exp1A*exp21)%MOD;
    count[3] = count[3]%MOD;
    count[3] += (exp11*exp2A)%MOD;
    count[3] = count[3]%MOD;
    count[3] += (exp1A*exp2A)%MOD;
    count[3] = count[3]%MOD;
    return count;
}
vector<ll> or_operator(ll exp10,ll exp11,ll exp1a,ll exp1A,ll exp20,ll exp21,ll exp2a,ll exp2A)
{
    vector<ll> count(4,0);
    //for 0
    count[0] += (exp10*exp20)%MOD;
    count[0] = count[0]%MOD;
    //for 1
    count[1] += (exp10*exp21)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp11*exp21)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp11*exp20)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp11*exp2a)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp1a*exp21)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp1A*exp21)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp11*exp2A)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp1A*exp2a)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp1a*exp2A)%MOD;
    count[1] = count[1]%MOD;
    //for a
    count[2] += (exp1a*exp20)%MOD;
    count[2] = count[2]%MOD;
    count[2] += (exp10*exp2a)%MOD;
    count[2] = count[2]%MOD;
    count[2] += (exp1a*exp2a)%MOD;
    count[2] = count[2]%MOD;
    // for A
    count[3] += (exp1A*exp20)%MOD;
    count[3] = count[3]%MOD;
    count[3] += (exp10*exp2A)%MOD;
    count[3] = count[3]%MOD;
    count[3] += (exp1A*exp2A)%MOD;
    count[3] = count[3]%MOD;
    return count;
}
vector<ll> xor_operator(ll exp10,ll exp11,ll exp1a,ll exp1A,ll exp20,ll exp21,ll exp2a,ll exp2A)
{
    vector<ll> count(4,0);
    //for 0
    count[0] += (exp10*exp20)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp11*exp21)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp1a*exp2a)%MOD;
    count[0] = count[0]%MOD;
    count[0] += (exp1A*exp2A)%MOD;
    count[0] = count[0]%MOD;
    //for 1
    count[1] += (exp10*exp21)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp11*exp20)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp1a*exp2A)%MOD;
    count[1] = count[1]%MOD;
    count[1] += (exp1A*exp2a)%MOD;
    count[1] = count[1]%MOD;
    //for a
    count[2] += (exp1a*exp20)%MOD;
    count[2] = count[2]%MOD;
    count[2] += (exp10*exp2a)%MOD;
    count[2] = count[2]%MOD;
    count[2] += (exp1A*exp21)%MOD;
    count[2] = count[2]%MOD;
    count[2] += (exp11*exp2A)%MOD;
    count[2] = count[2]%MOD;
    // for A
    count[3] += (exp1A*exp20)%MOD;
    count[3] = count[3]%MOD;
    count[3] += (exp10*exp2A)%MOD;
    count[3] = count[3]%MOD;
    count[3] += (exp1a*exp21)%MOD;
    count[3] = count[3]%MOD;
    count[3] += (exp11*exp2a)%MOD;
    count[3] = count[3]%MOD;
    return count;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll c=0;
        vector<vector<ll>> ExpCalc;
        string ip;
        cin>>ip;
        for (ll i=0;i<ip.size();i++)
            if(ip[i]=='#')
                c++;
        if(ip.size()==1 && c==1)
        {
            ll q=power(4,c);
            q=power(q,998244351);
            cout<<((1*q)%MOD)<< " ";
            cout<<((1*q)%MOD)<< " ";
            cout<<((1*q)%MOD)<< " ";
            cout<<((1*q)%MOD)<< " ";
            cout<<endl;
            continue;
        }
        stack<char> exp;
        for(ll i=0;i<ip.size();i++)
        {
            if(ip[i]!=')')
                exp.push(ip[i]);
            else if(ip[i] == ')')
            {
                vector<char> temp(3);
                temp[0] = exp.top();
                exp.pop();
                temp[1] = exp.top();
                exp.pop();
                temp[2] = exp.top();
                exp.pop();
                exp.pop();
                if (temp[0] == '#' && temp[2] == '#')
                {
                    if(temp[1]=='&')
                        ExpCalc.push_back(and_operator(1,1,1,1,1,1,1,1));
                    else if(temp[1]=='^')
                        ExpCalc.push_back(xor_operator(1,1,1,1,1,1,1,1));
                    else if(temp[1]=='|')
                        ExpCalc.push_back(or_operator(1,1,1,1,1,1,1,1));
                    exp.push('@');
                }
                else if (temp[2] == '@' && temp[0] == '@')
                {
                    if(temp[1]=='&')
                        ExpCalc[ExpCalc.size()-2] = and_operator(ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3],ExpCalc[ExpCalc.size()-2][0],ExpCalc[ExpCalc.size()-2][1],ExpCalc[ExpCalc.size()-2][2],ExpCalc[ExpCalc.size()-2][3]);
                    else if(temp[1]=='^')
                        ExpCalc[ExpCalc.size()-2] = xor_operator(ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3],ExpCalc[ExpCalc.size()-2][0],ExpCalc[ExpCalc.size()-2][1],ExpCalc[ExpCalc.size()-2][2],ExpCalc[ExpCalc.size()-2][3]);
                    else if(temp[1]=='|')
                        ExpCalc[ExpCalc.size()-2] = or_operator(ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3],ExpCalc[ExpCalc.size()-2][0],ExpCalc[ExpCalc.size()-2][1],ExpCalc[ExpCalc.size()-2][2],ExpCalc[ExpCalc.size()-2][3]);
                    exp.push('@');
                    ExpCalc.erase(ExpCalc.begin()+ExpCalc.size()-1);
                }
                else if ((temp[2]=='@' && temp[0]=='#'))
                {
                    if(temp[1]=='&')
                        ExpCalc[ExpCalc.size()-1] = and_operator(ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3],1,1,1,1);
                    else if(temp[1]=='^')
                        ExpCalc[ExpCalc.size()-1] = xor_operator(ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3],1,1,1,1);
                    else if(temp[1]=='|')
                        ExpCalc[ExpCalc.size()-1] = or_operator(ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3],1,1,1,1);
                    exp.push('@');
                }
                else if ((temp[2]=='#' && temp[0]=='@'))
                {
                    if(temp[1]=='&')
                        ExpCalc[ExpCalc.size()-1] = and_operator(1,1,1,1,ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3]);
                    else if(temp[1]=='^')
                        ExpCalc[ExpCalc.size()-1] = xor_operator(1,1,1,1,ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3]);
                    else if(temp[1]=='|')
                        ExpCalc[ExpCalc.size()-1] = or_operator(1,1,1,1,ExpCalc[ExpCalc.size()-1][0],ExpCalc[ExpCalc.size()-1][1],ExpCalc[ExpCalc.size()-1][2],ExpCalc[ExpCalc.size()-1][3]);
                    exp.push('@');
                }
            }
        }
        ll q=power(4,c);
        q=power(q,998244351);
        cout << ((ExpCalc[0][0]*q)%MOD) << " ";
        cout << ((ExpCalc[0][1]*q)%MOD) << " ";
        cout << ((ExpCalc[0][2]*q)%MOD) << " ";
        cout << ((ExpCalc[0][3]*q)%MOD) << " ";
        cout << endl;
    }
    return 0;
} 
