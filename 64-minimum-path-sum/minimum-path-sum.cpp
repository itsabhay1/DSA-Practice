class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[i][j];
        if(i<0 || j<0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];
        int up = solve(i-1,j, grid, dp);
        int left = solve(i,j-1,grid, dp);

        int best = min(up, left);
        if (best == INT_MAX)
            return dp[i][j] = INT_MAX;

        return dp[i][j] = grid[i][j] + best;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1,m-1, grid, dp);
    }
};