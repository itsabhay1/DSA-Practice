class Solution {
public:
    int solve(int i, vector<int>&nums, vector<int>& dp){
        if(i==0) return nums[0];
        if(i<0) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(i-2, nums,dp);
        int nottake = solve(i-1,nums, dp);

        return dp[i] =  max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        // case1 - removing last house
        vector<int>a(nums.begin(), nums.end()-1);

        //case 2 - removing first house
        vector<int>b(nums.begin()+1, nums.end());

        vector<int>dp1(a.size(), -1);
        vector<int>dp2(b.size(), -1);

        
        return max(solve(a.size()-1, a, dp1), solve(b.size()-1, b, dp2));
    }
};