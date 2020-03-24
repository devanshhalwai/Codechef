https://www.codechef.com/FEB20B/problems/THEATRE
#include<bits/stdc++.h>
using namespace std;
long long int profit_of_the_day(long long int** request_mat)
{
    long long int profit=-400;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<4;k++)
            {
                for(int l=0;l<4;l++)
                {
                    if(i!=j && i!=k && i!=l && j!=k && j!=l && k!=l)
                    {
                        vector<int> movie_time(4);
                        movie_time[0]=request_mat[0][i];
                        movie_time[1]=request_mat[1][j];
                        movie_time[2]=request_mat[2][k];
                        movie_time[3]=request_mat[3][l];
                        sort(movie_time.begin(),movie_time.end());
                        int price=100;
                        long long int money=0;
                        for(int a=3;a>=0;a--)
                        {
                            if(movie_time[a]==0)
                                money+=-100;
                            else
                            {
                                money+=movie_time[a]*price;
                                price-=25;
                            }
                        }
                        if(money>profit)
                            profit=money;
                    }
                }
            }
        }
    }
    return profit;
}
int main()
{
    long long int t,total_profit=0;
    cin>>t;
    while(t--)
    {
        long long int **request_mat;
        request_mat=(long long int**)calloc(4,sizeof(long long int*));
        for(int i=0;i<4;i++)
            request_mat[i]=(long long int*)calloc(4,sizeof(long long int));
        long long int n;
        cin>>n;
        while(n--)
        {
            char movie;
            int time;
            cin>>movie>>time;
            request_mat[movie-65][time/3-1]++;
        }
        long long int ans=profit_of_the_day(request_mat);
        cout<<ans<<"\n";
        total_profit+=ans;
    }
    cout<<total_profit<<"\n";
    return 0;
}
