class Solution {
private:
    int subarray(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0, r=0, count=0, sum=0;
        int n = nums.size();
        while(r<n){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (subarray(nums, goal)- subarray(nums, goal-1));
    }
};