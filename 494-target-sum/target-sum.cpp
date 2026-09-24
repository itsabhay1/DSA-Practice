class Solution {
public:
    int solve(int ind, int sum, int target, vector<int>& nums){
        if(ind < 0){
            if(sum == target)return 1;
            else return 0;
        }

        int plus = solve(ind-1, sum+nums[ind], target, nums);
        int minus = solve(ind-1, sum-nums[ind], target, nums);

        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size()-1, 0, target, nums);
    }
};