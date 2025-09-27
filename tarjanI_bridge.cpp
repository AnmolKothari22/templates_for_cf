

                          /******************bridge finding/Tarjan *********************/

/*

ti->time of entry(declare all -1 intially)
le_ti->least time of entry amoungst adjacent that are not parent(declare all -1 intially)
num->used to know time(use as 1 during call)
brid will contain all edges which are bridges(in form {min,max} )

              ----process----

during first (and only) entering assign time(ti)
then dfs to find lowest times for its adjacents

if an adjacent 's lowest time is STRICTLY greater then time of cur time
then the edge from cur node and adjacent is a bridge

during exit assign min adj low to low of current



*/
#include <bits/stdc++.h>
#define ll long long 
using namespace std;




int brigder(int cur,int par ,vector<vector<int>>&adj,vector<int>&ti,vector<int>&le_ti,set<pair<int,int>>&brid,vector<int>&visited,int num){
    
    visited[cur]=1;

    ti[cur]=num;
    le_ti[cur]=ti[cur];

    for(int i=0;i<adj[cur].size();i++){
        if(adj[cur][i]==par)continue;
        if(visited[adj[cur][i]])continue;
        brigder(adj[cur][i],cur,adj,ti,le_ti,brid,visited,num+1);
    }

   

    for(int i=0;i<adj[cur].size();i++){
        if(adj[cur][i]==par)continue;
        if(ti[cur]<le_ti[adj[cur][i]]){
           brid.insert({min(cur,adj[cur][i]),max(cur,adj[cur][i])});
        }
        le_ti[cur]=min(le_ti[cur],le_ti[adj[cur][i]]);
    }

    return 0;

}



//*********************************************************************/
