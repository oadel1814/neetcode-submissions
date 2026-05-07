class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int> (2, -1));
        function<int(int, int)> go = [&](int i, int lst) {
            if (i == n) return 0;
            int &ret = dp[i][lst];
            if(~ret) return ret;

            return ret = max(go(i + 1, 1), lst ? go(i + 1, 0) + nums[i] : 0);
        };

        return go(0, 1);
    }
};
