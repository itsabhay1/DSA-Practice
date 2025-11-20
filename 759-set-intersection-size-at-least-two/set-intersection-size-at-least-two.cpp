class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            if(a[1] == b[1]) return a[0]>b[0];
            else return a[1] < b[1];
        });
        int last1 = -1 , last2 = -1;
        int res = 0;

        for(auto &it: intervals){
            int s = it[0];
            int e = it[1];

            bool last1_in = (last1>=s);
            bool last2_in = (last2>=s);

            if(last1_in && last2_in) continue;
            if(!last1_in && !last2_in){
                last2 = e;
                last1 = e-1;
                res += 2;
            }
            else{
                last1 = last2;
                last2 = e;
                res += 1;
            }
        }
        return res;
    }
};