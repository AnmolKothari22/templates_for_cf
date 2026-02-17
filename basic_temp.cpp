#include <bits/stdc++.h>
#define ll long long 
using namespace std;


template<typename T>
T print_v(vector<T>&v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
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
    cout <<fixed << std::setprecision(7); // Set to 7 decimal places
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(__null);//fast input output
    int n=1;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}