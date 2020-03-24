//https://www.codechef.com/MARCH20B/problems/ADASHOP2
#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define ll long long int
#define endl "\n"

int main() 
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        ll r,c;
        cin>>r>>c;
        if(r==1)
        {
            if(c==1)
                cout<<"19\n7 7\n6 8\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n";
            else if(c==3)
                cout<<"17\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==5)
                cout<<"17\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n8 4\n5 1\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==7)
                cout<<"16\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
        }
        if(r==2)
        {
            if(c==2)
                cout<<"18\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==4)
                cout<<"18\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==6)
                cout<<"18\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n8 4\n5 1\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==8)
                cout<<"17\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
        }
        if(r==3)
        {
            if(c==1)
                cout<<"18\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==3)
                cout<<"20\n1 1\n7 7\n6 8\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n";
            else if(c==5)
                cout<<"18\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==7)
                cout<<"18\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n8 4\n5 1\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
        }
        if(r==4)
        {
            if(c==2)
                cout<<"18\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n8 4\n5 1\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==4)
                cout<<"17\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==6)
                cout<<"18\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==8)
                cout<<"18\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n8 4\n5 1\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
        }
        if(r==5)
        {
            if(c==1)
                cout<<"18\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n8 4\n5 1\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==3)
                cout<<"17\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==5)
                cout<<"20\n1 1\n7 7\n6 8\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n";
            else if(c==7)
                cout<<"18\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
        }
        if(r==6)
        {
            if(c==2)
                cout<<"17\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==4)
                cout<<"18\n2 8\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==6)
                cout<<"20\n1 1\n7 7\n6 8\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n";
            else if(c==8)
                cout<<"18\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
        }
        if(r==7)
        {
            if(c==1)
                cout<<"17\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==3)
                cout<<"18\n2 8\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==5)
                cout<<"19\n3 1\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==7)
                cout<<"20\n1 1\n7 7\n6 8\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n";
        }
        if(r==8)
        {
            if(c==2)
                cout<<"18\n2 8\n1 7\n2 8\n8 2\n7 1\n2 6\n4 8\n8 4\n5 1\n1 5\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==4)
                cout<<"19\n4 8\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n8 4\n5 1\n2 4\n1 3\n3 1\n8 6\n6 8\n7 7\n8 8\n1 1\n";
            else if(c==6)
                cout<<"19\n3 1\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n8 8\n1 1\n";
            else if(c==8)
                cout<<"19\n1 1\n7 7\n6 8\n1 3\n3 1\n8 6\n6 8\n5 7\n8 4\n5 1\n1 5\n3 7\n8 2\n7 1\n1 7\n2 8\n3 7\n4 8\n6 6\n";
        }
    }
	return 0;
}