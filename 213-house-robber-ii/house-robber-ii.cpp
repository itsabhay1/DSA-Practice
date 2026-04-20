class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp) {
        dp[0] = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += dp[i - 2];
            int nottake = dp[i-1];

            dp[i] = max(take, nottake);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        // case1 - removing last house
        vector<int> a(nums.begin(), nums.end() - 1);

        // case 2 - removing first house
        vector<int> b(nums.begin() + 1, nums.end());

        vector<int> dp1(a.size(), 0);
        vector<int> dp2(b.size(), 0);

        return max(solve(a, dp1), solve(b, dp2));
    }
};