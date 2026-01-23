#include <bits/stdc++.h>
#define ll long long 
using namespace std;



// template for sum segment tree
// l,r is always inclusive
// its 0 based indexing
class sum_seg_tree{

    ll n;
    vector<ll>v;
    vector<ll>seg;

    public:
        ll build(int l,int r,int cur){
           // print_v(seg);
            if(l==r){
                seg[cur]=v[l];
                return v[l];
            }
            seg[cur]=build(l,(l+r)/2,2*cur+1)+build((l+r)/2+1,r,2*cur+2);
            return seg[cur];
        }
        sum_seg_tree(ll n,vector<ll>v){
            this->n=n;
            this->v=v;
            seg.resize(4*n+2);

            build(0,n-1,0);
        }
         ll query(ll q_l,ll q_r){
            return query2(q_l,q_r,0,n-1,0);
        }

        ll update(ll pos ,ll val){
            return update2(0,n-1,pos,val,0);
        }
    private:
         ll update2(int l,int r,int pos,int val,int cur){
            if(l==r && l==pos){
                seg[cur]=val;
                return 0;
            }
            ll mid=(l+r)/2;
            if(pos<=mid){
                update2(l,mid,pos,val,2*cur+1);
            }
            else{
                update2(mid+1,r,pos,val,2*cur+2);
            }
            seg[cur]=seg[2*cur+1]+seg[2*cur+2];
            return 0;
        }

        ll query2(int q_l,int q_r,int l,int r,int cur){

            if(q_r>=r && q_l<=l){
                return seg[cur];
            }
            if(q_r<l || q_l>r){
                return 0;
            }
  
            ll mid=l+(r-l)/2;
            return query2(q_l,q_r,l,mid,2*cur+1)+query2(q_l,q_r,mid+1,r,2*cur+2);
        }
};


// same conditions as sum one

class min_seg_tree{

    ll n;

    vector<ll>v;
    vector<ll>seg;

    public:
        ll build(int l,int r,int cur){
           // print_v(seg);
            if(l==r){
                seg[cur]=v[l];
                return v[l];
            }
            seg[cur]=min(build(l,(l+r)/2,2*cur+1),build((l+r)/2+1,r,2*cur+2));
            return seg[cur];
        }
        min_seg_tree(ll n,vector<ll>v){
            this->n=n;
            this->v=v;
            seg.resize(4*n+2);

            build(0,n-1,0);
        }

        ll query(ll q_l,ll q_r){
            return query2(q_l,q_r,0,n-1,0);
        }

        ll update(ll pos ,ll val){
            return update2(0,n-1,pos,val,0);
        }

    private:
         ll update2(int l,int r,int pos,int val,int cur){
            if(l==r && l==pos){
                seg[cur]=val;
                return 0;
            }
            ll mid=(l+r)/2;
            if(pos<=mid){
                update2(l,mid,pos,val,2*cur+1);
            }
            else{
                update2(mid+1,r,pos,val,2*cur+2);
            }
            seg[cur]=min(seg[2*cur+1],seg[2*cur+2]);
            return 0;
        }

        ll query2(int q_l,int q_r,int l,int r,int cur){

            if(q_r>=r && q_l<=l){
                return seg[cur];
            }
            if(q_r<l || q_l>r){
                return INT64_MAX;
            }
  
            ll mid=l+(r-l)/2;
            return min(query2(q_l,q_r,l,mid,2*cur+1),query2(q_l,q_r,mid+1,r,2*cur+2));
        }
        
};










