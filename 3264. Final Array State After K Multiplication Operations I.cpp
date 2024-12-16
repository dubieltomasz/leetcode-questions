class Solution {
public:
    std::vector<int> getFinalState(std::vector<int>& nums, int k, const int multiplier) {
        while(k--)
        {
            nums[std::min_element(nums.begin(), nums.end()) - nums.begin()] *= multiplier;
        }
        
        return nums;
    }
};
