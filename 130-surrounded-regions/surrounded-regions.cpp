class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board){
        vis[row][col] = 1;

        int dRow[] = {0,-1,0,1};
        int dCol[] = {-1,0,1,0};

        for(int i =0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col+ dCol[i];

            if(nRow >= 0 && nRow < board.size() && nCol >= 0 && nCol < board[0].size() && !vis[nRow][nCol] && board[nRow][nCol] == 'O'){
                dfs(nRow, nCol, vis, board);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int j=0; j<n; j++){
            // first row
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,vis,board);
            }

            // last row
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1,j,vis,board);
            }
        }

        for(int i=0; i<m; i++){
            // first col
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board);
            }

            // last col
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i,n-1,vis,board);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};