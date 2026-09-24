class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 1e9);

        for(int T=0; T<= amount; T++){
            if(T % coins[0] == 0) dp[T] = T / coins[0];
        }

        for(int i=1; i<n; i++){
            for(int T=0; T<= amount; T++){
                int np = dp[T];
                int p = 1e9;
                if(T>= coins[i]) p = 1 + dp[T-coins[i]];
                dp[T] = min(np,p);
            }
        }
        return dp[amount] >= 1e9 ? -1: dp[amount];
    }
};