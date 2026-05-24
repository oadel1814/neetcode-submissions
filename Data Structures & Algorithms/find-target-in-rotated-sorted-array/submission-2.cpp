class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        function<int(int, int)> go = [&](int l, int r) {
            if (l == r) return nums[l] == target ? l : -1;
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return mid;

            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && nums[mid] >= target) return go(l, mid);
                else return go(mid + 1, r);
            } else {
                if (nums[mid] <= target && nums[r] >= target) return go(mid + 1, r);
                else return go(l, mid);
            }
        };

        return go(0, n - 1);
    }
};
