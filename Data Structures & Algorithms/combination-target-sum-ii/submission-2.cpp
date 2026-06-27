class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int, int)> dfs = [&](int start, int remain) {
            if (remain == 0) {
                ans.push_back(cur);
                return;
            }

            for (int i = start; i < candidates.size(); i++) {
                // Skip duplicates at the same recursion level
                if (i > start && candidates[i] == candidates[i - 1])
                    continue;

                // Since the array is sorted, no need to continue
                if (candidates[i] > remain)
                    break;

                cur.push_back(candidates[i]);
                dfs(i + 1, remain - candidates[i]); // each number used once
                cur.pop_back();
            }
        };

        dfs(0, target);
        return ans;
    }
};