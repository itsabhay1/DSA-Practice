class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<pair<int,int>>allNums;
        for(int i =0; i<k; i++){
            for(int x: nums[i]){
                allNums.push_back({x,i});
            }
        }

        sort(allNums.begin(), allNums.end());

        vector<int>freq(k,0);
        int covered = 0;
        int l=0;
        int bestL=0, bestR= INT_MAX;
        int n = allNums.size();

        for(int r=0; r<n; r++){
            int listIndex = allNums[r].second;
            if(freq[listIndex] == 0) covered++;
            freq[listIndex]++;

            while(covered == k){
                int start = allNums[l].first;
                int end = allNums[r].first;

                if((end-start < bestR-bestL) || (end-start == bestR-bestL && start < bestL)){
                    bestL = start;
                    bestR = end;
                }

                freq[allNums[l].second]--;
                if(freq[allNums[l].second] == 0) covered--;
                l++;
            }
        }
        return {bestL, bestR};
    }
};