class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j < 32; j++) {
                if ((1 << j) & i) ans[i]++;
            }
        }

        return ans;
    }
};
