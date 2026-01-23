

                          /******************bridge finding/Tarjan *********************/

/*

returns all bridges in a vector
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




vector<pair<int,int>> bridges(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> tin(n, -1), low(n, -1);
    int timer = 0;
    vector<pair<int,int>> res;
    function<void(int,int)> dfs = [&](int u, int parent) {
        tin[u] = low[u] = timer++;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (tin[v] != -1) {
                // back-edge
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);

                if (low[v] > tin[u]) {
                    res.push_back({u, v}); // (u, v) is a bridge
                }
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (tin[i] == -1)
            dfs(i, -1);
    }
    return res;
}



//*********************************************************************/
