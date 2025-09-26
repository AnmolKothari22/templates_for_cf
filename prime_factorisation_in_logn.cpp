


/*
this is algo for prime factorisation in  logn
1:for this ...we will find the smallest prime factor for each number in  particular range (max 10^7 tk)
using sieve ....eg 2 will first mark 2,4,6,8.... then 3 will mark 3,9,15...so on . wherever you find 0
you  have to mark that number with prime.  


*/




#include <bits/stdc++.h>
#define ll long long 
using namespace std;


 //sieve to generate primes




vector<ll> sie(){
    ll n =200050;
    vector<ll>primes(n,1);
    vector<ll>ans;
    for(ll i=2;i<n;i++){
        if(primes[i]==0){
            continue;
        }
        ans.push_back(i);
        for(ll j=2*i;j<n;j=j+i){
            primes[j]=0;
        }
    } 
   // print(ans);
    return ans;
}


int main(){
    vector<ll>pri=sie();
 
    vector<ll>sm_p(200100); //range for number till which  you want to find prime factristion
    sm_p[1]=1;

    //sm_p will contain  the smallest prime for all 
    for(ll i=0;i<pri.size();i++){
        for(ll j=pri[i];j<sm_p.size();j=j+pri[i]){
            if(sm_p[j]==0){
                sm_p[j]=pri[i];
            }
        }
    }
    //to get prime prime factoristion  just dec a element by its smallest prime and then decrease that number 
    //from  its smallest prime while keeping track  of all the primes seen

}
 


 
 
 






