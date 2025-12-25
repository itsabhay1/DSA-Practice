class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        long long num = 0, sum = 0;
        int i =0;
        while(k){
            long long happy = happiness[i];
            if((happy-num) >= 0){
                sum += happy-num;
            }
            num++;
            i++;
            k--;
        }
        return sum;
    }
};