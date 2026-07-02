class Solution {
private:
    void dfs(int sr, int sc, vector<vector<int>>& ans, int iniColor, int color){

        if(sr<0 || sc<0 || sr >= ans.size() || sc >= ans[0].size() || ans[sr][sc] != iniColor){
            return;
        }
        
        if(ans[sr][sc] == iniColor){
            ans[sr][sc] = color;
        }
        dfs(sr, sc+1, ans, iniColor, color);
        dfs(sr, sc-1, ans, iniColor, color);
        dfs(sr+1, sc, ans, iniColor, color);
        dfs(sr-1, sc, ans, iniColor, color);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        if(iniColor == color) return image;

        vector<vector<int>> ans = image;
        dfs(sr,sc,ans,iniColor,color);
        return ans;
    }
};