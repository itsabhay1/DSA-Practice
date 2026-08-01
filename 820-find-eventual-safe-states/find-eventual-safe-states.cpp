class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> adjRev[v];
        vector<int> indegree(v, 0);

        for(int i=0; i<v; i++){
            for(auto &it: graph[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safe;

        for(int i=0; i<v; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            safe.push_back(node);
            q.pop();

            for(auto &neigh: adjRev[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0) q.push(neigh);
            }
            
        }
        sort(safe.begin(), safe.end());
        return safe;


    }
};