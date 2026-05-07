class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> freq(n, vector<int>(26, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < strs[i].size(); j++) {
                freq[i][strs[i][j] - 'a']++;
            }
        }
         
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> mp;

        for(int i = 0; i < n; i++) {
            mp[freq[i]].push_back(strs[i]);
        }

        for(auto &[u, v] : mp) ans.push_back(v);
        return ans;
    }
};
