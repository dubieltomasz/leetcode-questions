class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int i = nums.size()-1, sum = nums[i--];

        while(i >= 0 && nums[i] > 0)
        {
            while(i >= 0 && nums[i] == nums[i+1])
                --i;

            if(i < 0 || nums[i] <= 0) break;

            sum += nums[i--];
        }

        return sum;
    }
};
