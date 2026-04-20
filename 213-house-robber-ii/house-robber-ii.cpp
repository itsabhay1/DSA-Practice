class Solution {
public:
    int solve(vector<int>& nums) {
       int prev2 = 0;
       int prev = nums[0];
       int n = nums.size();

       for(int i=1; i<n; i++){
        int take = nums[i] + prev2;
        int notTake = prev;
        int curr = max(take, notTake);

        prev2 = prev;
        prev = curr;
       }
       return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        // case1 - removing last house
        vector<int> a(nums.begin(), nums.end() - 1);

        // case 2 - removing first house
        vector<int> b(nums.begin() + 1, nums.end());

        return max(solve(a), solve(b));
    }
};