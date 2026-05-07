class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        const int N = 1e3 * 2 + 10;
        vector<pair<int, int>> freq(N);

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i] + 1001].first++;
            freq[nums[i] + 1001].second = nums[i];
        }

        sort(freq.rbegin(), freq.rend());
        vector<int> ans;
        for(int i = 0; i < freq.size(); i++) {
            if (!k) break;
            if (freq[i].first) ans.push_back(freq[i].second), k--; 
        }

        return ans;
    }
};
