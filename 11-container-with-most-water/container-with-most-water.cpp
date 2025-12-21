class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0;
        int n = height.size();
        int r = n-1;
        long long result = INT_MIN;
        while(l<r){
            if(height[l]<height[r]){
                result = max(result, height[l]*1LL*(r-l));
                l++;
            }
            else{
                result = max(result, height[r]*1LL*(r-l));
                r--;
            }
        }
        return result;
    }
};