class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int k = sum / 2;

        vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= k) dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {
                bool np = dp[i - 1][target];
                bool p = false;
                if (target >= nums[i]) p = dp[i - 1][target - nums[i]];

                dp[i][target] = p || np;
            }
        }

        return dp[n-1][k];
    }
};