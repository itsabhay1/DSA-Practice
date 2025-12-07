class Solution {
private:
    int largeHist(vector<int>& heights){
        heights.push_back(0);  // Sentinel to clear stack
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                st.pop();
                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        heights.pop_back();  // Remove sentinel if you want to preserve original
        return maxArea;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == '1'){
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largeHist(heights));
        }
        return maxArea;
    }
};