class Solution {
public:
    int minRemoval(std::vector<int>& nums, const int k) {
        std::ranges::sort(nums);

        int l = 0, r = 0, n = 0;

        while(l < nums.size()) {
            while(r < nums.size() && static_cast<long>(nums[l]) * k >= nums[r]) {
                ++r;
            }
            
            n = std::max(n, r - l);

            if(r == nums.size()) {
                break;
            }

            while(l < r && static_cast<long>(nums[l]) * k < nums[r]) {
                ++l;
            }
        }

        return nums.size() - n;
    }
};
