class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size(), m = board[0].size();

        function<bool(int,int,int)> dfs = [&](int i, int x, int y) {
            if (i == word.size()) return true;

            if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] != word[i])
                return false;

            char temp = board[x][y];
            board[x][y] = '#';

            bool found = dfs(i+1, x+1, y) || dfs(i+1, x-1, y) ||
                         dfs(i+1, x, y+1) || dfs(i+1, x, y-1);

            board[x][y] = temp;

            return found;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(0, i, j)) return true;
            }
        }

        return false;
    }
};
