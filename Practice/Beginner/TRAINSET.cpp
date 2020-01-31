//https://www.codechef.com/problems/TRAINSET
#include<iostream>
#include<map>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    while(num--){
        int subTests;
        cin >> subTests;
        int counter = 0;
        map<string,pair<int,int>> inputs;
        while(subTests--){
            string name;
            int value;
            cin >> name >> value;
            if(value == 1){
                inputs[name].first++;
            }else{
                inputs[name].second++;
            }
        }
        
        for(auto i = inputs.begin() ; i != inputs.end() ; i++){
                counter+=max(i->second.first,i->second.second);
        }
        cout << counter << endl;
    }
    return 0;
}