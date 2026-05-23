class Solution {
public:
    bool check(const std::vector<int>& nums) {
        bool canBeRotated = true;
        
        if(nums.front() < nums.back()) {
            canBeRotated = false;
        }

        for(size_t i = 1; i < nums.size(); ++i) {
            if(nums[i - 1] > nums[i]) {
                if(canBeRotated) {
                    canBeRotated = false;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};
