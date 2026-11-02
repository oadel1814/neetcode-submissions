class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        int mx = -1;
        for (int i = n - 1; i >= 0; i--) {
            ans.push_back(mx);
            if (arr[i] > mx) mx = arr[i];
        }

        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};