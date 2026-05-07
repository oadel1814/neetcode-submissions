class Solution {
   private:
    int to_square(int i, int j) { return (i / 3) * 3 + (j / 3); }

   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int row[9] = {0};
        int col[9] = {0};
        int square[9] = {0};

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;

                int x = board[r][c] - '0';
                if (row[r] & (1 << x) || col[c] & (1 << x) || square[to_square(r, c)] & (1 << x)) return false;

                row[r] |= (1 << x);
                col[c] |= (1 << x);
                square[to_square(r, c)] |= (1 << x);                
            }
        }

        return true;

    }
};
