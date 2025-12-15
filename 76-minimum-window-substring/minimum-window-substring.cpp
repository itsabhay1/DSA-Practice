class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty() || s.length() < t.length()) {
            return "";
        }
        int l=0, r=0, count=0, startIndex = -1;
        int minLen = INT_MAX;
        vector<int>hash(128,0);
        for(char c:t){
            hash[c]++;
        }
        while(r < s.length()){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;

            while(count == t.length()){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    startIndex = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return startIndex == -1? "": s.substr(startIndex, minLen);


    }
};