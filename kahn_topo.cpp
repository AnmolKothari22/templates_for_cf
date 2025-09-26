
#include <bits/stdc++.h>
using namespace std;
//*******************kahn***********************//

int kahn(vector<vector<int>>&adj,int n){
    // n is total number of nodes
    queue<int>q;
    vector<int>indeg(n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<adj[i].size();j++){
            indeg[adj[i][j]]++;
        }
    }
    for(int i=1;i<=n;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        for(int i=0;i<adj[q.front()].size();i++){
            indeg[adj[q.front()][i]]--;
            if(indeg[adj[q.front()][i]]==0){
                q.push(adj[q.front()][i]);
            }
        }
        ans.push_back(q.front());
        q.pop();
    }
    //if ans 's lenght ==n then there is linear ordering
    return !(ans.size()==n);
}