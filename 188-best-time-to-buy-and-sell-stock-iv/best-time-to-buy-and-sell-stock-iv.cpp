class Solution {
public:
    int f(int i, int transNo, int k, int n, vector<int> &prices, vector<vector<int>>& dp){
        if(i == n || transNo == 2*k) return 0;

        if(dp[i][transNo] != -1) return dp[i][transNo];

        if(transNo%2 == 0){  //buy
            return dp[i][transNo] = max(-prices[i] + f(i+1, transNo+1, k, n, prices, dp), 
            0 + f(i+1, transNo, k, n, prices, dp)
            );
        }
        else{  // sell
            return dp[i][transNo] = max(prices[i] + f(i+1, transNo+1, k, n, prices, dp),
            0 + f(i+1, transNo, k, n, prices, dp)
            );
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return f(0, 0, k, n, prices, dp);
    }
};