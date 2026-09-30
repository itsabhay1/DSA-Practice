class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = accumulate(stones.begin(), stones.end(), 0);

        int target = sum/2;

        vector<bool> dp(target+1, 0);

        dp[0] = true;
        for(int stone: stones){
            for(int k = target; k>= stone; k--){
                dp[k] = dp[k] || dp[k-stone];
            }
        }

        for(int k = target; k>=0; k--){
            if(dp[k]){
                return sum-2*k;
            }
        }
        return 0;
        
    }
};