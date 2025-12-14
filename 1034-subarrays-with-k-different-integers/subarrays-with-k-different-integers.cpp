class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return (subarray(nums,k) - subarray(nums, k-1));
    }

    int subarray(vector<int>& nums, int k) {
        int l=0, r=0, cnt=0;
        int n= nums.size();
        unordered_map<int, int>mpp;
        while(r<n){
            if(k<0) return 0;
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0){
                    mpp.erase(nums[l]);
                }
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
};