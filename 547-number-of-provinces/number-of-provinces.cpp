class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& isConnected){
        vis[node] = 1;

        for(int i =0; i< isConnected.size(); i++){
            if(isConnected[node][i] == 1 && !vis[i]){
                dfs(i , vis, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> vis(V,0);
        int cnt = 0;
        for (int i = 0; i<V; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, vis, isConnected);
            }
        }
        return cnt;
    }
};