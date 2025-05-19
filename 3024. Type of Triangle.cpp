class Solution {
public:
    std::string triangleType(const std::vector<int>& nums) {
        if(nums[0] + nums[1] <= nums[2] || nums[0] + nums[2] <= nums[1] || nums[1] + nums[2] <= nums[0])
            return "none";
        else if(nums[0] == nums[1] && nums[1] == nums[2])
            return "equilateral";
        else if(nums[0] == nums[1] || nums[1] == nums[2] || nums[0] == nums[2])
            return "isosceles";
        else return "scalene";
    }
};
