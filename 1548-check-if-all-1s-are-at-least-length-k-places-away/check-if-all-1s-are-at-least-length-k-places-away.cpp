class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
       
        int curr = -1;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if( nums[i] == 1){
                if(curr !=-1){
                    if(i-curr -1 < k ) return false ;
                }
                curr = i;
            }
        }
        return true;
    }
};