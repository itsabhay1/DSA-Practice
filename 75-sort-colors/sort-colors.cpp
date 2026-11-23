class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0;
        int n = nums.size();
        int high = n-1;

        for(int i=0; i<n; i++){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid] == 1)mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};