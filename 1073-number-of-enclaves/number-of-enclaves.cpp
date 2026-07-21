class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<int, int>> q;

        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && grid[0][j] == 1) {
                vis[0][j] = 1;
                q.push({0, j});
            }

            if (!vis[n - 1][j] && grid[n - 1][j] == 1) {
                vis[n - 1][j] = 1;
                q.push({n - 1, j});
            }
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && grid[i][0] == 1) {
                vis[i][0] = 1;
                q.push({i, 0});
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1) {
                vis[i][m - 1] = 1;
                q.push({i, m - 1});
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, -1, 0, 1};

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }

        int cnt = 0;
        for(int i =0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};