class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();

        
        vector<int> f(256);
        int mx = 0;
        int l = 0, r = 0; 
        while (r < n) {
            f[s[r]]++;
            while(f[s[r]] > 1) {
                f[s[l]]--;
                l++;
            }

            mx = max(mx, r - l + 1);
            r++;
        }
        
        return mx;
    }
};
