class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int t1 = accumulate(nums.begin(), nums.end(), 0);

        int tar = (t1-target)/2;

        if(t1-target <0 || (t1-target)%2) return 0;

        int n = nums.size();
        vector<int>dp(tar+1,0);

        if(nums[0] == 0) dp[0] = 2;
        else dp[0] = 1;

        if(nums[0] != 0 && nums[0] <= tar) dp[nums[0]] = 1;

        for(int ind = 1; ind < n; ind++){
            for(int k = tar; k>= nums[ind]; k--){
                int np = dp[k];
                int p = dp[k-nums[ind]];

                dp[k] = p+np;
            }
        }
        return dp[tar];
    }
};