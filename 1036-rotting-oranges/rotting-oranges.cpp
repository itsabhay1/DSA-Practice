class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> vis = grid;
        int fresh = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int drow[4] = {-1,0,1,0};
        int dcol[4] = {0,-1,0,1};
        int minutes = 0;

        while(!q.empty() && fresh > 0){
            int sz = q.size();

            while(sz--){
                auto [r,c] = q.front();
                q.pop();

                for(int i=0; i<4; i++){
                    int nr = r + drow[i];
                    int nc = c + dcol[i];

                    if(nr >= 0 && nc >= 0 && nr<n && nc <m && vis[nr][nc] == 1 ){
                        vis[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            minutes ++;
        }

        return fresh == 0 ? minutes : -1;
    }
};