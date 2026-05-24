class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m));
        function<bool(int, int)> ok = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && !vis[i][j] && grid[i][j] == 1; 
        };

        function<int(int, int)> go = [&](int i, int j) {

            vis[i][j] = 1;
            int area = 1;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x * x + y * y == 1) {
                        int nx = x + i, ny = j + y;
                        if (ok(nx, ny)) area += go(nx, ny);
                    }
                }
            }

            return area;
        };


        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) ans = max(ans, go(i, j)); 
            }
        }

        return ans;

    }
};
