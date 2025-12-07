class Solution {
private:
    int largeHist(vector<int>& matrix){
        matrix.push_back(0);
        int n = matrix.size();
        vector<int>st;
        int res = 0;
        for(int i=0; i<n; i++){
            while(!st.empty() && matrix[st.back()] >= matrix[i]){
                int  nse = i;
                int element = st.back(); st.pop_back();
                int pse = st.empty()? -1 : st.back();
                res = max(res, matrix[element]*(nse-pse-1));
            }
            st.push_back(i);
        }
        return res;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> prefixSum(row, vector<int>(col, 0));
        for(int j=0; j<col; j++){
            int sum =0;
            for(int i=0; i<row; i++){
                sum += (matrix[i][j]-'0');
                if(matrix[i][j]=='0') sum =0;
                prefixSum[i][j] = sum;
            }
        }
        int maxArea = 0;
        for(int i =0; i<row; i++){
            maxArea = max(maxArea, largeHist(prefixSum[i]));
        }
        return maxArea;
    }
};