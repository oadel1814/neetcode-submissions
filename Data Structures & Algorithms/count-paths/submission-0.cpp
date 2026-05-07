class Solution {
public:
    int uniquePaths(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        function<int(int, int)> go = [&](int i, int j) -> int {
            if (i == n || j == m) return 0;
            if (i == n - 1 && j == m - 1) return 1;
            if (~dp[i][j]) return dp[i][j];

            return dp[i][j] = go(i + 1, j) + go(i, j + 1);
        };

        return go(0, 0);
    }
};
