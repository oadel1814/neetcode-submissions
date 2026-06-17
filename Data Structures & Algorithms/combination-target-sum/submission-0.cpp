class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;
        vector<int> cur;

        function<void(int, int)> go = [&](int i, int target) {
            if (i == n || target < 0) {
                return;
            }

            if (!target) {
                ans.push_back(cur);
                return;
            }

            cur.push_back(nums[i]);
            go(i, target - nums[i]);
            cur.pop_back();

            go(i + 1, target);
        };

        go(0, target);
        return ans;
    }
};
