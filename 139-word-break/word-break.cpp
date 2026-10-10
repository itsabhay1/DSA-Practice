class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_set<string> st(wordDict.begin(), wordDict.end());

       int n = s.size();

       vector<bool>dp(n+1, 0);

       dp[0] = true;

       for(int i=1; i<=n; i++){
        string temp = "";
        for(int j =i; j>=1; j--){
            temp = s[j-1] + temp;
            if(st.find(temp) != st.end() && dp[j-1]){
                dp[i] = true;
                break;
            }
        }
       }
       return dp[n];
       
    }
};