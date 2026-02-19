class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i =1;
        int sum = 1;

        while(i<n){
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int up=0;
            while(i<n && ratings[i] > ratings[i-1]){
                up++;
                sum += 1+up;
                i++;
            }

            int down = 0;
            while(i<n && ratings[i] < ratings[i-1]){
                down++;
                sum += 1+down;
                i++;
            }

             sum -= min(up, down);
        }
        return sum;
    }
};