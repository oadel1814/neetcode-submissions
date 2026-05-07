class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        function<int(int)> go = [&](int i) {
            if (i > n) return 0;
            if (i == n) return 1;
            if(~dp[i]) return dp[i];

            return dp[i] = go(i + 1) + go(i + 2);
        };

        return go(0);
    }
};
