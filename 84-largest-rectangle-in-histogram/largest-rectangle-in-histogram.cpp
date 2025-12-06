class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        vector<int> st;
        int res = 0;
        for(int i = 0, n = heights.size(); i < n; ++i){
            int curr = heights[i];
            while(!st.empty() && heights[st.back()] >= curr){
                int h = heights[st.back()]; st.pop_back();
                int last = st.empty() ? -1 : st.back();
                res = max(res , h * (i - last - 1));
            }
            st.push_back(i);
        }
        return res;
    }
};