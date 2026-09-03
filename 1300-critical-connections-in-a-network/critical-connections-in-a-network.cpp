class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis,
             int tin[], int low[], vector<vector<int>>& critical) {
                vis[node] = 1;
                tin[node] = low[node] = timer;
                timer++;

                for(auto& it: adj[node]){
                    if(it == parent) continue;
                    if(vis[it] == 0){
                        dfs(it, node, adj, vis, tin, low, critical);
                        low[node] = min(low[node], low[it]);

                        if(tin[node] < low[it]){
                            critical.push_back({it,node});
                        }
                    }
                    else{
                        low[node] = min(low[node], tin[it]);
                    }
                }
             }

public:
    vector<vector<int>> criticalConnections(int n,vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int low[n];
        int tin[n];
        vector<vector<int>> critical;
        dfs(0,-1,adj, vis,tin,low,critical);
        return critical;
    }
};