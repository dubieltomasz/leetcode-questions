class Solution {
public:
    int countHillValley(const std::vector<int>& nums) {
        uint size = nums.size(), left = 0, right = 1, count = 0;

        while(right < size)
        {
            while(right < size && nums[left] == nums[right-1])
                right++;

            if(right == size)
                break;

            while(right < size && nums[right-1] == nums[right])
                right++;

            if(right == size)
                break;

            if(nums[left] < nums[right-1] && nums[right-1] > nums[right] ||
               nums[left] > nums[right-1] && nums[right-1] < nums[right])
                ++count;

            left = right-1;
            ++right;
        }

        return count;
    }
};
