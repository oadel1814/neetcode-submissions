class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<int, int> f1, f2;
        for(int i = 0; i < s.size(); i++)  {
            f1[s[i]]++;
        }

        for(int i = 0; i < t.size(); i++)  {
            f2[t[i]]++;
        }

        return f1 == f2;
    }
};
