class Solution {
public:
    bool solve(int ind, int target, vector<int>& nums, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[0] == target);

        if(dp[ind][target] != -1) return dp[ind][target];
        bool np = solve(ind-1, target, nums, dp);
        bool p = false;
        if(target >= nums[ind]) p = solve(ind-1, target-nums[ind], nums, dp);

        return dp[ind][target] = p||np;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum%2 != 0) return false;

        int k = sum/2;

        vector<vector<int>> dp(n, vector<int>(k+1,-1));

        return solve(n-1, k, nums, dp);
    }
};