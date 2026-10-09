class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int>dp(m+1, 0);
        for(int j=0; j<=m; j++) dp[j] = j;

        for(int i=1; i<=n; i++){
            int prevDiag =dp[0];
            dp[0] = i;
            for(int j=1; j<=m; j++){
                int temp = dp[j];
                if(word1[i-1] == word2[j-1]) dp[j] = prevDiag;
                else{
                    int del = dp[j];
                    int ins = dp[j-1];
                    int repl = prevDiag;

                    dp[j] = 1 + min({del, ins, repl});
                }
                prevDiag = temp;
            }
        }

        return dp[m];
    }
};