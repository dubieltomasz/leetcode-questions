class Solution {
public:
    int minimumCost(const std::vector<int>& nums) {
        int minimum = 52, minimum2 = 51;

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] < minimum) {
                minimum2 = minimum;
                minimum = nums[i];
            } else if(nums[i] < minimum2) {
                minimum2 = nums[i];
            }
        }

        return nums[0] + minimum + minimum2;
    }
};
