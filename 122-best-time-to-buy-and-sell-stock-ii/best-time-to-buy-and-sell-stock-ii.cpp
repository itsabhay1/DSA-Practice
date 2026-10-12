class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2,0);
        ahead[0] = ahead[1] = 0;

        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
            if(buy){
                int b = -prices[i] + ahead[0];
                int nb = 0 + ahead[1];
                curr[buy] = max(b, nb);
            }

            else{
                int s = prices[i] + ahead[1];
                int ns = 0 + ahead[0];
                curr[buy] = max(s, ns);
            }
            }
            ahead = curr;
        }
        return ahead[1];
    }
};