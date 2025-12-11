class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, maxLen = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] == 0)
                k--;

            if (k < 0) {
                if (nums[l] == 0)
                    k++;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};