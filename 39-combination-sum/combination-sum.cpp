class Solution {
public:
    void findCombination(int ind, vector<vector<int>>& ans, vector<int>& ds,
                         vector<int>& arr, int target) {
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        if (ind == arr.size())
            return;

        if (arr[ind] <= target) {
            ds.push_back(arr[ind]);
            findCombination(ind, ans, ds, arr, target - arr[ind]);
            ds.pop_back();
        }
        
        findCombination(ind + 1, ans, ds, arr, target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, ans, ds, candidates, target);
        return ans;
    }
};