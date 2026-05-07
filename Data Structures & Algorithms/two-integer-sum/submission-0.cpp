class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> ans = {-1, -1};
        for(int i = 0; i < nums.size(); i++) {
            if (!mp.contains(target - nums[i])) mp[nums[i]] = i;
            else {
                ans = {i, mp[target - nums[i]]};
                sort(ans.begin(), ans.end());
                return ans;
            }
        }
        return ans;
    }
};
