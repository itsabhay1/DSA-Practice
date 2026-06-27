class Solution {
private:
void dfs(int row, int col, vector<vector<char>>& grid){

    int n = grid.size();
    int m = grid[0].size();

    if(row >= n || col >= m || row < 0 || col < 0 || grid[row][col] == '0'){
        return;
    }
    grid[row][col] = '0';

    dfs(row+1,col,grid);
    dfs(row-1,col,grid);
    dfs(row,col+1,grid);
    dfs(row,col-1,grid);
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
                    dfs(i,j,grid);
                }
            }
        }
        return cnt;
    }
};