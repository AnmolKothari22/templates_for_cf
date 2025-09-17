

//******** to find furthest distance form each node in a tree ********// 
/*

find the diameter of tree ....then from top top most node of diameter do dfs 
marking the location of diameter from furthest end of diameter.keep an parent 
array also so that you may not go up during dfs for marking diameter...

now from each vertecx form dia just dfs distance for each non dia node



*/





int dia_find(int cur,int par,vector<vector<int>>&adj,int &ma,int &dia,vector<int>&dep,vector<int>&pa){
    //for diameter's top node and diameter's lenght finding
    //ma is top node and dia is diameter
    //it also maintains parent array 
    //dep is depth
    //ma is top node
    //dia is diameter
    
    pa[cur]=par;
    vector<int>di;
    for(int i=0;i<adj[cur].size();i++){
        if(adj[cur][i]==par){
            continue;
        }
        di.push_back(1+dia_find(adj[cur][i],cur,adj,ma,dia,dep,pa));
    }
    sort(di.begin(),di.end());


    if(di.size()>1){
        if((di[di.size()-1]+di[di.size()-2]+1)>dia){
            dia=di[di.size()-1]+di[di.size()-2]+1;
            ma=cur;
           // cout<<cur<<endl;
        }
        dep[cur]=di[di.size()-1];
    }
    else if(di.size()==1){
        if(di[di.size()-1]+1>dia){
            dia=di[di.size()-1]+1;
            ma=cur;
           // cout<<cur<<endl;
        }
        dep[cur]=di[di.size()-1];
    }
    else{
        dep[cur]=0;
    }



    if(di.size()>=1){
        return di[di.size()-1];
    }
    else{
        return 0;
    }

}



void marker(int cur,int par,vector<vector<int>>&adj,vector<int>&mark,vector<int>&dep,int inh,bool b,vector<int>&pa){

    // for marking closest distance for diameter elements
    //mark is distance of furthest end of diameter 
    //inh is dist from end of other branch
    //b is boolean for top node of dia
    //pa is parent array
    vector<int>edg;

    for(int i=0;i<adj[cur].size();i++){

        if(adj[cur][i]==par)continue;
        if(adj[cur][i]==pa[cur])continue;
        edg.push_back(dep[adj[cur][i]]+1);
        
    }
   // print(edg);

    sort(edg.begin(),edg.end());
    if(edg.size()==0){
        mark[cur]=inh;
        return;
    }
    mark[cur]=edg[edg.size()-1];


    if(b){
        if(edg.size()==1){
            marker(adj[cur][0],cur,adj,mark,dep,1,0,pa);
        }
        else{
            int si=-1;
            for(int i=0;i<adj[cur].size();i++){
                if(par==adj[cur][i])continue;
                if(adj[cur][i]==pa[cur])continue;
                if((dep[adj[cur][i]]+1)==edg[edg.size()-1]){
                    marker(adj[cur][i],cur,adj,mark,dep,1+edg[edg.size()-2],0,pa);
                    si=i;
                    break;
                }
            }

            for(int i=0;i<adj[cur].size();i++){
                if(par==adj[cur][i])continue;
                if(adj[cur][i]==pa[cur])continue;
                if(i==si)continue;
                if((dep[adj[cur][i]]+1)==edg[edg.size()-2]){
                    marker(adj[cur][i],cur,adj,mark,dep,1+edg[edg.size()-1],0,pa);
                    break;
                }
            }
        }
    }
    else{
        mark[cur]=max(edg[edg.size()-1],inh);
       
        for(int i=0;i<adj[cur].size();i++){
            if(par==adj[cur][i])continue;
            if(adj[cur][i]==pa[cur])continue;
            if((dep[adj[cur][i]]+1)==edg[edg.size()-1]){
                marker(adj[cur][i],cur,adj,mark,dep,1+inh,0,pa);
                break;
            }
        }

    }



}




void khali(int cur,int par,vector<vector<int>>&adj,vector<int>&mark){
   // cout<<cur<<endl;
   //this is for finding furthest for each non diametric node
    for(int i=0;i<adj[cur].size();i++){
        if(adj[cur][i]==par)continue;
        if(mark[adj[cur][i]]==-1){
            mark[adj[cur][i]]=mark[cur]+1;
            khali(adj[cur][i],cur,adj,mark);
        }
        else{
            khali(adj[cur][i],cur,adj,mark);
        }
    }
}


