class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount = 0;
        int ind = 0;
        int m = mat.size();
        int n = mat[0].size();
        for(int i =0; i<m; i++){
            int cntOnes = count(mat[i].begin(), mat[i].end(),1);
            if(cntOnes>maxCount){
                maxCount = cntOnes;
                ind = i;
            }
        }
        return {ind,maxCount};
    }
};