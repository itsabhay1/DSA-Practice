class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l =0, r=0, maxLen=0, zeroes=0;
        int n = nums.size();
        while(r<n){
            if(nums[r] == 0) zeroes++;
            while(zeroes>k){
                if(nums[l] == 0) zeroes--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};