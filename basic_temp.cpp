#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define ll long long 
using namespace std;



template<typename T>
void print_r(T itr_start,T itr_end){
    for(T itr=itr_start;itr!=itr_end;itr++){
        cout<<(*itr)<<" ";
    }
    cout<<endl;
}
//use print(<linear data structure(except arrays)> to print it)
template<typename T>
void print(T ds){
    print_r(ds.begin(),ds.end());
}


void dbug() {
    cout <<endl;
}

template<typename T, typename... Args>
void dbug(T firstArg, Args... args) { //
    cout << firstArg << " ";
    dbug(args...); // Recursive call for the rest of the arguments
}


// usage : __gnu_pbds::gp_hash_table<ll,ll, custom_hash> mp;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



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