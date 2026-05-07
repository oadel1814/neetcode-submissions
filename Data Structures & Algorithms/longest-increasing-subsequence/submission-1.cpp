class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        function<int(int, int)> go = [&](int i, int lst) {
            if (i == n) return 0;
            if (~dp[i][lst + 1]) return dp[i][lst + 1];
            return dp[i][lst + 1] = max(go(i + 1, lst), lst == -1 || nums[lst] < nums[i]? go(i + 1, i) + 1 : 0);
        };
        
        return go(0, -1);
    }
};
