
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int aheadBuy = 0, aheadSell = 0;

        for(int i = prices.size() - 1; i >= 0; i--) {
            int currBuy = max(-prices[i] + aheadSell, aheadBuy);
            int currSell = max(prices[i] + aheadBuy, aheadSell);

            aheadBuy = currBuy;
            aheadSell = currSell;
        }

        return aheadBuy;
    }
};
