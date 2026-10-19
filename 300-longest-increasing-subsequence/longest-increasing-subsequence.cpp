class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp (n+1, vector<int>(n+1, 0));
        for(int i = n-1; i>=0; i--){
            for(int prevIndx = i-1; prevIndx>= -1; prevIndx--){
                int notTake = 0 + dp[i+1][prevIndx+1];
                int take = 0;
                if(prevIndx == -1 || nums[i] > nums[prevIndx]){
                    take = 1 + dp[i+1][i+1];
                }
                dp[i][prevIndx+1] = max(take, notTake);   
            }
        }
        return dp[0][0];
    }
};