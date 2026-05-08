func threeSum(nums []int) [][]int {

	sort.Ints(nums)

	var res [][]int

	for i := 0; i < len(nums); i++ {
        if nums[i] > 0 {
            break
        }

		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		l, r := i+1, len(nums)-1

		for l < r {
			sum := nums[i] + nums[l] + nums[r]

			if sum > 0 {
				r--
			} else if sum < 0 {
				l++
			} else {
				cur := []int{nums[i], nums[l], nums[r]}
				res = append(res, cur)

				l++
				r--

				for l < r && nums[l] == nums[l-1] {
					l++
				}
			}
		}
	}

	return res
}