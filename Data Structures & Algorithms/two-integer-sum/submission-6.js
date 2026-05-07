class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    twoSum(nums, target) {
        let mp = new Map()
        for (let i = 0; i < nums.length; i++) {
            if (!mp.has(target - nums[i])) mp.set(nums[i], i)
            else {
                return [Math.min(i, mp.get(target - nums[i])), Math.max(i, mp.get(target - nums[i]))]
            }
        }

        return [-1, -1]
    }
}