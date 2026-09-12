class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> prev(m,0);

        for(int i=0; i<n; i++){
            vector<int> curr(m,0);
            for(int j=0; j<m; j++){
                if(i==0 && j==0) curr[j] = grid[i][j];
                else {
                    int left = INT_MAX, up = INT_MAX;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];

                    curr[j] = grid[i][j] + min(left,up);
                }
            }
            prev = curr;
        }
        return prev[m-1];
    }
};