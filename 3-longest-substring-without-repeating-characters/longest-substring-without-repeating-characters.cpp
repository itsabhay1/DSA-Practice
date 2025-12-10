class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int hash[256];
        fill(hash, hash + 256, -1);
        int l =0, r=0, maxLen = 0;
        while(r<n){
                if(hash[s[r]] >= l){
                    l = hash[s[r]] + 1;
                }
            hash[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};