class Solution {
public:
    int f(int i, int prevIndx, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(i == n) return 0;

        if(dp[i][prevIndx+1] != -1) return dp[i][prevIndx+1];

        int notTake = 0 + f(i+1, prevIndx, n, nums, dp);
        int take = 0;
        if(prevIndx == -1 || nums[i] > nums[prevIndx]){
            take = 1 + f(i+1, i, n, nums, dp);
        }

        return dp[i][prevIndx+1] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp (n, vector<int>(n+1, -1));
        return f(0, -1, n, nums, dp);
    }
};