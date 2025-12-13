class Solution {
public:
    int subarray(vector<int>& nums, int k) {
        int l=0, r=0, cnt=0, odd=0;
        int n = nums.size();
        while(r<n){
            if(nums[r]&1) odd++;
            while(odd>k){
                if(nums[l]&1){        // if l is odd then remove otherwise keep it
                    odd--;
                }
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (subarray(nums, k) - subarray(nums, k-1));
    }
};