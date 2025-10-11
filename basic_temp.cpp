#include <bits/stdc++.h>
#define ll long long 
using namespace std;


void print_v(vector<int>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}


void print_mp(map<int,int>&mp){
    for(auto itr = mp.begin();itr!=mp.end();itr++){
        cout<<(itr->first)<<"=>>"<<(itr->second)<<"   ";
    }
}

void print_set(set<int>&se){
     for(auto itr = se.begin();itr!=se.end();itr++){
        cout<<(*itr)<<" ";
    }
}







void solve(){



}



int main(){
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}