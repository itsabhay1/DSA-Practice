class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26] = {0};
        for(char ch: s){
            freq[ch-'a']++;
        }
        for(char ch: t){
            freq[ch-'a']--;
        }

        for(auto a: freq){
            if(a != 0) return false;
        }
        return true;
    }
};