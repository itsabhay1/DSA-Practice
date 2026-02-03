class Solution {
public:
    int start = 0;
    int end = 0;
    void expandFromCenter(string& s, int left, int right){
        int n = s.length();
        while(left>=0 && right<=n-1 && s[left] == s[right]){
            left--;
            right++;
        }
        int length = right-left-1;
        if(length>end-start+1){
            start = left+1;
            end = right-1;
        }
    }
    string longestPalindrome(string s) {
        int n = s.length();
        for(int i=0; i<n; i++){
            expandFromCenter(s,i,i);
            expandFromCenter(s,i,i+1);
        }
        return s.substr(start,end-start+1);
    }
};