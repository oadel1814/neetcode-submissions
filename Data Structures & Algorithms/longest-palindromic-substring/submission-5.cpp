class Solution {
public:
    string longestPalindrome(string s) {
        
        int start = 0, end = 0, mx_len = 1;
        for (int i = 0; i < s.size(); i++) {
            // odd length
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > mx_len) {
                    mx_len = r - l + 1;
                    start = l, end = r;
                } 

                l--, r++;
            }


            // even length
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r - l + 1 > mx_len) {
                    mx_len = r - l + 1;
                    start = l, end = r;
                } 

                l--, r++;
            }
        }

        return s.substr(start, end - start + 1);
    }
};
