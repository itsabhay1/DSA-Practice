class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n+1, 0), curr(n+1, 0);
        for(int i = n-1; i>=0; i--){
            for(int prevIndx = i-1; prevIndx>= -1; prevIndx--){
                int notTake = 0 + next[prevIndx+1];
                int take = 0;
                if(prevIndx == -1 || nums[i] > nums[prevIndx]){
                    take = 1 + next[i+1];
                }
                curr[prevIndx+1] = max(take, notTake);   
            }
            next = curr;
        }
        return next[0];
    }
};