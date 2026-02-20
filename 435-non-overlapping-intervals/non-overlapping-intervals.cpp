class Solution {
public:
    static bool comp(vector<int> a, vector<int> b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        int lastIntvl = intervals[0][1];
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastIntvl) {
                cnt++;
                lastIntvl = intervals[i][1];
            }
        }
        return n - cnt;
    }
};