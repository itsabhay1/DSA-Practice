class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) return false;

        int k = sum / 2;

        vector<bool> prev(k + 1, 0), curr(k+1,0);

        prev[0] = curr[0] = true;
        if (nums[0] <= k) prev[nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int target = 1; target <= k; target++) {
                bool np = prev[target];
                bool p = false;
                if (target >= nums[i]) p = prev[target - nums[i]];

                curr[target] = p || np;
            }
            prev = curr;
        }

        return prev[k];
    }
};