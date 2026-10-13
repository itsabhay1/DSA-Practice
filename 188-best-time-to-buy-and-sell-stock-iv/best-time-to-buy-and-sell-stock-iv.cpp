class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead(2, vector<int>(k+1, 0)), curr(2, vector<int>(k+1, 0));
        
        for(int i = n-1; i>=0; i--){
            for(int buy =0; buy<=1; buy++){
                for(int cap =0; cap <k; cap ++){
                    int maxP = 0;
                    if(buy){
                        maxP = max(-prices[i] + ahead[0][cap],
                        ahead[1][cap]);
                    }
                    else{
                        maxP = max(prices[i] + ahead[1][cap+1],
                        ahead[0][cap]);
                    }

                    curr[buy][cap] = maxP;
                }
            }
            ahead = curr;
        }
        return ahead[1][0];
    }
};