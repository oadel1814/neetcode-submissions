class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        

        vector<vector<string>> ans;
        vector<string> cur(n, string(n, '.'));


        unordered_set<int> col, d1, d2;
        function<void(int, vector<string>&)> go = [&](int r, vector<string> &cur) {
            if (r == n) {
                ans.push_back(cur);
                return;
            }

            for(int c = 0; c < n; c++) {
                if (col.count(c) || d1.count(r - c) || d2.count(r + c)) continue;
                
                cur[r][c] = 'Q';
                col.insert(c);
                d1.insert(r - c);
                d2.insert(r + c);

                go(r + 1, cur);

                cur[r][c] = '.';
                col.erase(c);
                d1.erase(r - c);
                d2.erase(r + c);

            }
        };

        go(0, cur);

        return ans;
    }
};
