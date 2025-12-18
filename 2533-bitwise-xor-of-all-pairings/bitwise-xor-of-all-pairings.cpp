class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int r = 0;

        if (nums1.size() % 2 == 1) {
            for (int x : nums2) r ^= x;
        }

        if (nums2.size() % 2 == 1) {
            for (int x : nums1) r ^= x;
        }

        return r;
    }
};
