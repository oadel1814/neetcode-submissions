class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        set<pair<int, int>> vis;

        function<bool(int, int)> ok = [&](int i, int j) {
            return i >= 0 && i < n && j >= 0 && j < m && !vis.count({i, j}) && grid[i][j] == '1';
        };

        function<void(int, int)> go = [&](int i, int j) {
            vis.insert({i, j});

            for (int x = -1; x <= 1; x++) {
                for(int y = -1; y <= 1; y++) {
                    if (x * x + y * y == 1) {
                        int nx = i + x, ny = j + y;
                        if (ok(nx, ny)) {
                            go(nx, ny);
                        }
                    }
                }
            }
        };

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (ok(i, j)) {
                    ans++;
                    go(i, j);
                } 
            }
        }

        return ans;
    }
};
