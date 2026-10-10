class Solution {
public:
    bool f(int i, string &s, unordered_set<string>& st, vector<int>& dp){
        if(i<0) return true;

        if(dp[i] != -1) return dp[i];
        string temp = "";
        for(int j = i; j>=0; j--){
            temp = s[j] + temp;
            if(st.find(temp) != st.end()){
                if(f(j-1, s, st, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string> st(wordDict.begin(), wordDict.end());

       int n = s.size();

       vector<int>dp(n, -1);

       return f(n-1, s, st, dp);
    }
};