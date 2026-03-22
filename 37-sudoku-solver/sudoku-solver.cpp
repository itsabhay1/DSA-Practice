class Solution {
public:
    vector<unordered_set<char>> rows, cols, boxes;

    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(9);
        cols.resize(9);
        boxes.resize(9);
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    char c = board[i][j];
                    rows[i].insert(c);
                    cols[j].insert(c);
                    boxes[(i/3)*3 + (j/3)].insert(c);
                }
            }
        }
        solve(board);
    }

private:
    bool solve(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(char c = '1'; c <= '9'; c++){
                        int boxIndex = (i/3)*3 + (j/3);

                        // Check if c is already used
                        if(rows[i].count(c) == 0 &&
                           cols[j].count(c) == 0 &&
                           boxes[boxIndex].count(c) == 0){

                            // Place the number
                            board[i][j] = c;
                            rows[i].insert(c);
                            cols[j].insert(c);
                            boxes[boxIndex].insert(c);

                            // Recurse
                            if(solve(board)) return true;

                            // Backtrack
                            board[i][j] = '.';
                            rows[i].erase(c);
                            cols[j].erase(c);
                            boxes[boxIndex].erase(c);
                        }
                    }
                    return false; // No number worked here → backtrack
                }
            }
        }
        return true;
    }
};