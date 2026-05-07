class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> ans;
        for (const auto &s : strs) {
            vector<int> freq(26);
            for (char c : s) {
                freq[c - 'a']++;
            }

            string k = to_string(freq[0]);
            for (int i = 1; i < 26; i++) {
                k += ", " + to_string(freq[i]);
            }

            ans[k].push_back(s);
        }

        vector<vector<string>> res;   
        for (const auto& [u, v] : ans) {
            res.push_back(v);
        }

        return res;
    }
};
