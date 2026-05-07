class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for (int i = 0; i < s.size(); i++) {
            if (isalnum(s[i])) t += std::tolower(s[i]);
        }
        
        cout << t;
        int l = 0, r = t.size() - 1;
        while (l <= r) {
            if (t[l] != t[r]) return false;
            l++; r--;
        }

        return true;
    }
};
