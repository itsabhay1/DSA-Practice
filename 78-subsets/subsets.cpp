class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        int subset = 1<<n;
        for(int num = 0; num<subset; num++){
            vector<int>list;
            for(int i =0; i<n; i++){
                if(num & (1<<i)) {
                    list.push_back(nums[i]);
                }
            }
            res.push_back(list);
        }
        return res;
    }
};