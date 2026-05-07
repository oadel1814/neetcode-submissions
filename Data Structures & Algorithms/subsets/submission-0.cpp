class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n = nums.size();
        function<void(int i, vector<int>&)> go = [&](int i, vector<int>& cur) {
            if (i == n) {
                ans.push_back(cur);
                return;
            }

            cur.push_back(nums[i]);
            go(i + 1, cur);
            cur.pop_back();
            go(i + 1, cur);
        };

        vector<int> cur;
        go(0, cur);
        return ans;
    }
};
