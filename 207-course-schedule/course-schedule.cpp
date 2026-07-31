class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);

        for(auto edge: prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        int cnt = 0;

        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(auto neigh: adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }

        }

        if(cnt == numCourses) return true;
        return false;
        
    }
};