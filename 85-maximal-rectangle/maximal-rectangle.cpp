class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;

        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols + 1, 0);   // +1 sentinel
        vector<int> st;                     // faster than stack
        st.reserve(cols + 1);

        int maxArea = 0;

        for(int i = 0; i < rows; i++) {

            // Update histogram
            for(int j = 0; j < cols; j++) {
                heights[j] = (matrix[i][j] == '1') ? heights[j] + 1 : 0;
            }

            // Monotonic stack with sentinel
            st.clear();

            for(int j = 0; j <= cols; j++) {
                while(!st.empty() && heights[st.back()] >= heights[j]) {
                    int height = heights[st.back()];
                    st.pop_back();
                    int left = st.empty() ? -1 : st.back();
                    maxArea = max(maxArea, height * (j - left - 1));
                }
                st.push_back(j);
            }
        }
        return maxArea;
    }
};
