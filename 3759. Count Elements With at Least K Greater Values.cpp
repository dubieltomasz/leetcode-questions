class Solution {
public:
    int countElements(std::vector<int>& nums, int k) {
        if(k == 0) {
            return std::move(nums.size());
        }

        std::sort(nums.begin(), nums.end());
        int i = nums.size() - 1 - k;
        
        while(i >= 0 && nums[i] == nums[i + 1]) {
            --i;
        }

        return i + 1;
    }
};
