class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size()%2;
        int m = nums2.size()%2;
        int r=0;
        if(n==0 && m == 1){
            for(int i=0; i<nums1.size(); i++){
                r = r^nums1[i];
            }
            return r;
        }
        else if(n ==1 && m==0){
            for(int i=0; i<nums2.size(); i++){
                r = r^nums2[i];
            }
            return r;
        }
        else if(n==1 && m==1){
            for(int i=0; i<nums1.size(); i++){
                r = r^nums1[i];
            }
            for(int i=0; i<nums2.size(); i++){
                r = r^nums2[i];
            }
            return r;
        }
        return r;

    }
};