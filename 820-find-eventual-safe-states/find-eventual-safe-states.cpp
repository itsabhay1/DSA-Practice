class Solution {
private:
    bool dfs(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& graph, vector<int>& check){
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto  it: graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,graph,check)){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);
        vector<int> check(v, 0);
        vector<int> safe;

        for(int i=0; i<v; i++){
            if(!vis[i]){
                dfs(i,vis,pathVis,graph,check);
            }
        }

        for(int i=0; i<v; i++){
            if(check[i] == 1){
                safe.push_back(i);
            }
        }

        return safe;
    }
};