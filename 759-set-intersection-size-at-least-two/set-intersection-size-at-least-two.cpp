class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b){
            return a[1] < b[1];
        });
        vector<int>chosen;

        for(auto &it: intervals){
            int s = it[0];
            int e = it[1];

            int cnt = 0;
            for(int x: chosen){
                if(x >= s && x <= e) cnt++;
            }

            for(int x =e; cnt<2; x--){
                if(find(chosen.begin(), chosen.end(), x) == chosen.end()){
                    chosen.push_back(x);
                    cnt++;
                }
            }
        }
        return chosen.size();
    }
};