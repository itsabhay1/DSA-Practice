class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i =0; i<n; i++){
            for(int prevIndx =0; prevIndx < i; prevIndx++){
                if(nums[prevIndx] < nums[i]){
                    dp[i] = max(1+dp[prevIndx], dp[i]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};