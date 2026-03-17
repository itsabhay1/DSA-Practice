class Solution {
public:
    void premuteAns(vector<int>& ds, vector<int>& nums,
                    vector<vector<int>>& ans, vector<int>& freq) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!freq[i]) {
                ds.push_back(nums[i]);
                freq[i] = 1;
                premuteAns(ds, nums, ans, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n = nums.size();
        vector<int> freq(n,0);
        premuteAns(ds, nums, ans, freq);
        return ans;
    }
};