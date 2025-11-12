class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        long long maxVal = 0;
        long long prevSum = 0;
        vector<long long>result;
        for(int i = 0; i<nums.size(); i++){
            maxVal = max(maxVal,(long long)nums[i]);
            long long sum = nums[i]+maxVal;
            prevSum = sum + prevSum;
            result.push_back(prevSum);
        }
        return result;
    }
};