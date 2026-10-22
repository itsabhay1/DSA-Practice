class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
       vector<int> dp(n,1), hash(n);
       sort(nums.begin(), nums.end());

       int maxi = 1;
       int lastIndex = 0;

       for(int i=0; i<n; i++){
        hash[i] = i;
        for(int prevIndx=0; prevIndx<i; prevIndx++){
            if(nums[i] % nums[prevIndx] == 0 && 1 + dp[prevIndx] > dp[i]){
                dp[i] = 1 + dp[prevIndx];
                hash[i] = prevIndx;
            }
        }

        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
       }

       vector<int>temp;
       temp.push_back(nums[lastIndex]);

       while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
       }

       reverse(temp.begin(), temp.end());

       return temp;
    }
};