class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [1,2,4,6]
        int n = nums.size();
        vector<int> p(n, 1), s(n, 1);

        p[0] = nums[0];
        s[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) p[i] *= p[i - 1] * nums[i];
        for (int i = n - 2; i >= 0; i--) s[i] *= s[i + 1] * nums[i]; 

        vector<int> res(n);

        for (int i = 0; i < n; i++) {
            if (!i) res[i] = s[i + 1];
            else if (i == n - 1) res[i] = p[i - 1];
            else {
                res[i] = p[i - 1] * s[i + 1];
            }
        }

        return res;
    }
};
