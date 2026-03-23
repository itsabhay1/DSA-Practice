class Solution {
public:
    bool valid(string& s, int i, int j){
        while(i<=j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    void palindrome(int i, string s, vector<string>& ds, vector<vector<string>>&ans){
        if(i==s.length()){            ans.push_back(ds);
            return;
        }
        for(int j=i; j<s.length(); j++){
            string str = s.substr(i,j-i+1);
            if(valid(s,i,j)){
                ds.push_back(str);
                palindrome(j+1, s, ds, ans);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>ds;
        palindrome(0,s,ds,ans);
        return ans;
    }
};