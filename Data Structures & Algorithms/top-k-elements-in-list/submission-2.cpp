class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, vector<int>> mp;
        unordered_map<int, int> freq;
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (!st.count(nums[i])) mp[-freq[nums[i]]].push_back(nums[i]);
            st.insert(nums[i]);
        }

        vector<int> ans;
        for(auto &[freq, v] : mp) {
            if (!k) break;
            for (auto x : v) {
                if (!k) break;
                ans.push_back(x);
                k--;
            }
        }

        return ans;
    }
};
