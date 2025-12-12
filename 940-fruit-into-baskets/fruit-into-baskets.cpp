class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int k=2, l=0, r=0, maxLen=0;
        unordered_map<int,int>mpp;
        int n = fruits.size();
        while(r<n){
            mpp[fruits[r]]++;
            if(mpp.size()>k){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]]==0){
                    mpp.erase(fruits[l]);
                }
                l++;
            }
            if(mpp.size()<=k){
                maxLen = max(maxLen, r-l+1);
            }
            r++;
        }
        return maxLen;
    }
};