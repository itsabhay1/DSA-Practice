class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<int>&pathVis, vector<vector<int>>&adj){
        vis[node] = 1;
        pathVis[node] = 1;

        for(auto neigh: adj[node]){
            if(!vis[neigh]){
                if(dfs(neigh,vis,pathVis,adj) == false) return false;
            }

            else if(pathVis[neigh]) return false;
        }

        pathVis[node] = 0;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for(auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses,0);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj) == false) return false;
            }
        }
        return true;
        
    }
};