class Solution {
public:
    string largestOddNumber(string num) {
        reverse(num.begin(), num.end());
        string ans = "";
        for(int i=0; i<num.length(); i++){
            if((num[i]-'0')%2 != 0){
                ans += num.substr(i);
                break;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};