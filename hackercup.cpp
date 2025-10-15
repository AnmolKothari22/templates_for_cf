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



static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    
    func();
    asm volatile("mov (%0), %%rsp\n" :: "r"(send));
    free(stack);
}





void main_(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n=1;
    cin>>n;
    int n_c=n;

    while(n--){
        cout<<"Case #"<<n_c-n<<": ";
        solve();
    }

}

int main(){
    run_with_stack_size(main_,512LL*1024LL*1024LL);
    return 0;
}
