class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
            if(buy){
                int b = -prices[i] + dp[i+1][0];
                int nb = 0 + dp[i+1][1];
                dp[i][buy] = max(b, nb);
            }

            else{
                int s = prices[i] + dp[i+1][1];
                int ns = 0 + dp[i+1][0];
                dp[i][buy] = max(s, ns);
            }
            }
        }
        return dp[0][1];
    }
};