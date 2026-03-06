#include <bits/stdc++.h>
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
    print(ds.begin(),ds.end());
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