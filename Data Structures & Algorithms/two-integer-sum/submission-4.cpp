class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> a;
        for(int i = 0; i < nums.size(); i++) a.push_back({nums[i], i});
        sort(a.begin(), a.end());
        int l = 0, r = a.size() - 1;
        while (l < r) {
            int cur_sum = a[l].first + a[r].first;
            if (cur_sum == target) return {min(a[l].second, a[r].second), 
                                           max(a[l].second, a[r].second)};
            if (cur_sum > target) r--;
            else l++;
        }

        return {-1, -1};
    }
};
