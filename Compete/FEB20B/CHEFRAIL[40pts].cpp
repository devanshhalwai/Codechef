//https://www.codechef.com/FEB20B/problems/CHEFRAIL
#include<bits/stdc++.h>
#include<fstream>
using namespace std;
int binarySearch(vector<long long int> arr,long long int l,long long int r,long long int x) 
{ 
    while (l <= r) 
    { 
        int m=l+(r-l)/2; 
        if(arr[m]==x) 
            return m; 
        if(arr[m]<x) 
            l=m+1; 
        else
            r=m-1; 
    } 
    return -1; 
} 
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n,m,temp,x1,y1,x2,y2,x3,y3,ans=0;
        bool flag=false;
        cin>>n>>m;
        vector<long long int> x_pos;
        vector<long long int> y_pos;
        vector<long long int> x_neg;
        vector<long long int> y_neg;
        for(long long int i=0;i<n;i++)
        {
            cin>>temp;
            if(temp>0)
                x_pos.push_back(temp);
            if(temp<0)
                x_neg.push_back(temp);
            if(temp==0)
                flag=true;
        }
        for(long long int i=0;i<m;i++)
        {
            cin>>temp;
            if(temp>0)
                y_pos.push_back(temp);
            if(temp<0)
                y_neg.push_back(temp);
            if(temp==0)
                flag=true;
        }
        sort(x_pos.begin(),x_pos.end());
        sort(y_pos.begin(),y_pos.end());
        sort(x_neg.begin(),x_neg.end());
        sort(y_neg.begin(),y_neg.end());
        for(long long int i=0;i<x_pos.size();i++)
        {
            x1=x_pos[i];
            y1=0;
            for(long long int j=0;j<y_pos.size();j++)
            {
                x2=0;
                y2=y_pos[j];
                long double yPoint = (long double)(x1*x1*-1.0)/y2;
                x3=0;
                if(yPoint == (int)yPoint && binarySearch(y_neg,0,y_neg.size()-1,(int)yPoint)!=-1)
                {
                        cout<<"x1: "<<x1<<" y1: "<<y1<<" x2: "<<x2<<" y2: "<<y2<<" x3: "<<x3<<" y3: "<<yPoint<<"\n";
                        ans++;
                }
            }
        }
        for(long long int i=0;i<x_neg.size();i++)
        {
            x1=x_neg[i];
            y1=0;
            for(long long int j=0;j<y_pos.size();j++)
            {
                x2=0;
                y2=y_pos[j];
                long double yPoint = (long double)(x1*x1*-1.0)/y2;
                x3=0;
                if(yPoint == (int)yPoint && binarySearch(y_neg,0,y_neg.size()-1,(int)yPoint)!=-1)
                {
                        cout<<"x1: "<<x1<<" y1: "<<y1<<" x2: "<<x2<<" y2: "<<y2<<" x3: "<<x3<<" y3: "<<yPoint<<"\n";
                        ans++;
                }
            }
        }
        for(long long int i=0;i<y_pos.size();i++)
        {
            x1=0;
            y1=y_pos[i];
            for(long long int j=0;j<x_pos.size();j++)
            {
                x2=x_pos[j];
                y2=0;
                long double xPoint = (long double)(y1*y1*-1.0)/x2;
                y3=0;
                if(xPoint == (int)xPoint && binarySearch(x_neg,0,x_neg.size()-1,(int)xPoint)!=-1)
                {
                        cout<<"x1: "<<x1<<" y1: "<<y1<<" x2: "<<x2<<" y2: "<<y2<<" x3: "<<xPoint<<" y3: "<<y3<<"\n";
                        ans++;
                }
            }
        }
        for(long long int i=0;i<y_neg.size();i++)
        {
            x1=0;
            y1=y_neg[i];
            for(long long int j=0;j<x_pos.size();j++)
            {
                x2=x_pos[j];
                y2=0;
                long double xPoint = (long double)(y1*y1*-1.0)/x2;
                y3=0;
                if(xPoint == (int)xPoint && binarySearch(x_neg,0,x_neg.size()-1,(int)xPoint)!=-1)
                {
                        cout<<"x1: "<<x1<<" y1: "<<y1<<" x2: "<<x2<<" y2: "<<y2<<" x3: "<<xPoint<<" y3: "<<y3<<"\n";
                        ans++;
                }
            }
        }
        if(flag==true)
            ans+=((x_pos.size()+x_neg.size())*(y_pos.size()+y_neg.size()));
        cout<<ans<<"\n";
    }
    return 0;
}