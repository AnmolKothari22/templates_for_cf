
int n=40,q;
vector <ll>vv;




long long int build(int l,int r,int cur,vector <ll> &seg ){

  if(l==r){
    seg[cur]=vv[l];
    return vv[l];
  }

  seg[cur]=min(build(l,(l+r)/2,2*cur+1,seg),build((l+r)/2+1,r,2*cur+2,seg));

  return seg[cur];
}



long long int query(vector <ll> &seg,int q_l,int q_r,int l,int r,int cur){
  //if(cur!=-1){cout<<cur<<endl;}

  if(   q_r>=r && q_l<=l){
    return seg[cur];
  }

  if(q_r<l || q_l>r){
    return INT64_MAX;
  }
  
    int mid=l+(r-l)/2;
    return min(query(seg,q_l,q_r,l,mid,2*cur+1),query(seg,q_l,q_r,mid+1,r,2*cur+2));
  

}




long long update(vector <ll> &seg,int l,int r,int pos,int val,int cur){
  //cout<<cur<<endl;
  if(l==r && l==pos){
    seg[cur]=val;
    return 0;
  }
  int mid=(l+r)/2;

  if(pos<=mid){
    update(seg,l,mid,pos,val,2*cur+1);
  }
  else{
    update(seg,mid+1,r,pos,val,2*cur+2);
  }

  seg[cur]=min(seg[2*cur+1],seg[2*cur+2]);

 
  return 0;
}




