class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            find i, j, k so that nums[i] + nums[j] + nums[k] = 0

            bf solution:
                n <= 1000
                if I iterate over i -> O(n) then j -> O(n^2) then I can get all possible sums between i, j 
                so I can save them in a hashmap and lookup in O(1) if hashmap[nums[i] + nums[j]] = some_index(k)
                then I return {i, j, k} 
            
            a better solution:
                - sort the array O(nlogn) -> [-4, -1, -1, 0, 1, 2]
                                   i   j            k
                - iterate over i [-4, -1, -1, 0, 1, 2] and use j, k as a two pointers to the right of i 
                then if (nums[j] + nums[k] > -nums[i]) we decrease k by 1 else if (nums[j] + nums[k] < -nums[i]) we increase i by one
                else if (nums[j] + nums[k] = -nums[i]) we save {i, j, k} as a valid answer then advance i by one and so on 
                this approach guarantees that we get unique triplets in O(n^2) 
        */

        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
             if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }
        

        return res;
    }
};
