class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<pair<int,int>>> adj(n);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        int cityNo = -1;
        int minCount = n;

        for (int src = 0; src < n; src++) {

            vector<int> dist(n, INT_MAX);
            priority_queue<
                pair<int,int>,
                vector<pair<int,int>>,
                greater<pair<int,int>>
            > pq;

            dist[src] = 0;
            pq.push({0, src});

            while (!pq.empty()) {

                auto [d, u] = pq.top();
                pq.pop();

                if (d > dist[u])
                    continue;

                for (auto [v, wt] : adj[u]) {

                    if (d + wt < dist[v] &&
                        d + wt <= distanceThreshold) {

                        dist[v] = d + wt;
                        pq.push({dist[v], v});
                    }
                }
            }

            int count = 0;

            for (int i = 0; i < n; i++) {
                if (dist[i] <= distanceThreshold)
                    count++;
            }

            if (count <= minCount) {
                minCount = count;
                cityNo = src;
            }
        }

        return cityNo;
    }
};