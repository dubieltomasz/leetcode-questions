class Solution {
public:
    int repeatedNTimes(const std::vector<int>& nums) {
        for(int i = 2; i < nums.size(); ++i) {
            if(nums[i - 2] == nums[i] || nums[i - 1] == nums[i]) {
                return nums[i];
            }
        }

        return nums.back();
    }
};
