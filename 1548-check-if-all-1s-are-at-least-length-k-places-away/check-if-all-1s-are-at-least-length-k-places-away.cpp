class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        bool flag = true ;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (!flag) {
                    if (count < k) {
                        return false;
                    }
                }
                count = 0;
                flag = false ;
            } else {
                if(!flag){
                    count ++ ;
                }
            }
        }
        return true;
    }
}
;