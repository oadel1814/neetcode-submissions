class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]] = 1;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            if (!mp[nums[i] - 1]) {
                int cur_len = 0;
                while (mp[nums[i] + cur_len]) cur_len++;
                ans = max(ans, cur_len);
                cur_len = 0;
            }
        }

        return ans;
    }
};
