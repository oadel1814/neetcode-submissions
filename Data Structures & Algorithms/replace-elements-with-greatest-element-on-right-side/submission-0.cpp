class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> suf(n, -1e6);
        suf[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suf[i] = max(suf[i + 1], arr[i]);
        }

        vector<int> ans(n, -1);
        for (int i = 0; i < n - 1; i++) {
            ans[i] = suf[i + 1];            
        }

        return ans;
        
    }
};