class Solution {
   private:
    unordered_map<char, int> col[9], row[9], square[9];
    int idx_to_square(int i, int j) { return (i / 3) * 3 + (j / 3); }

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                row[r][board[r][c]]++;
                col[c][board[r][c]]++;
                square[idx_to_square(r, c)][board[r][c]]++;
            }
        }

        for (int i = 0; i < 9; i++) {
            for (char c = '1'; c <= '9'; c++) {
                if (row[i][c] > 1 || col[i][c] > 1 || square[i][c] > 1) return false;
            }
        }

        return true;
    }
};
