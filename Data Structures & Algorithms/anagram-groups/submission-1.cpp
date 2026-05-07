class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        for (string &s : strs) { // O(m)
            string t = s;
            sort(t.begin(), t.end()); // O(n * log(n))
            mp[t].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto &[u, v] : mp) ans.push_back(v);
        return ans;
    }
};
