class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));

        for(int T=0; T<= amount; T++){
            if(T % coins[0] == 0) dp[0][T] = T / coins[0];
        }

        for(int i=1; i<n; i++){
            for(int T=0; T<= amount; T++){
                int np = dp[i-1][T];
                int p = 1e9;
                if(T>= coins[i]) p = 1 + dp[i][T-coins[i]];
                dp[i][T] = min(np,p);
            }
        }
        return dp[n-1][amount] >= 1e9 ? -1: dp[n-1][amount];
    }
};