class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pref = 1, suffix = 1;

        int n = nums.size();
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            if(pref == 0) pref = 1;
            if(suffix == 0) suffix = 1;

            pref = pref * nums[i];
            suffix = suffix* nums[n-i-1];
            maxi = max(maxi, max(suffix, pref));
            
        }
        return maxi;
    }
};