class Solution {
public:
    void generate(int open, int close, string str, int n, vector<string>& ans){
        if(n*2 == str.length()){
            ans.push_back(str);
            return;
        }
        if(open < n){
            generate(open+1, close, str + '(', n,ans);    
        }
        if(close < open){
            generate(open, close+1, str+')',n,ans);
        }

    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string>ans;
        generate(0,0,str,n,ans);
        return ans;
    }
};