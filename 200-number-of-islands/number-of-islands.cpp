class Solution {
private:
 void bfs(int row, int col, vector<vector<char>>& grid){
    queue<pair<int,int>>q;
    q.push({row,col});

    grid[row][col] = '0';

    int n = grid.size();
    int m = grid[0].size();

    vector<int> drow = {-1,0,1,0};
    vector<int> dcol = {0,1,0,-1};

    while(!q.empty()){
        auto [r,c] = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(nr>=0 && nc >=0 && nr<n && nc<m && grid[nr][nc] == '1'){
                q.push({nr,nc});
                grid[nr][nc] = '0';
            }
        }
    }
 }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int cnt = 0;

        for(int i = 0; i<n; i++){
            for(int j=0; j<m; j++){

                if(grid[i][j] == '1'){
                    cnt++;
                    bfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};