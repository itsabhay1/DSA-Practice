class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, 0), curr(amount+1, 0);

        for(int T=0; T<= amount; T++){
            if(T % coins[0] == 0) prev[T] = T / coins[0];
            else prev[T] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int T=0; T<= amount; T++){
                int np = prev[T];
                int p = 1e9;
                if(T>= coins[i]) p = 1 + curr[T-coins[i]];
                curr[T] = min(np,p);
            }
            prev = curr;
        }
        return prev[amount] >= 1e9 ? -1: prev[amount];
    }
};