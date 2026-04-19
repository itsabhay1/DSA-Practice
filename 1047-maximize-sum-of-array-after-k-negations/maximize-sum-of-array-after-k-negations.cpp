class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        int n = nums.size();
        for(int i=0; i<n; i++){
            pq.push(nums[i]);
        }
        while(!pq.empty() && k>0){
            int val = pq.top();
            pq.pop();
            val *= -1;
            pq.push(val);
            k--;
        }
        int res=0;
        while(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};