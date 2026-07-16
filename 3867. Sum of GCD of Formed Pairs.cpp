class Solution {
public:
    long long gcdSum(std::vector<int>& nums) {
        long long sum = 0;
        int mx = 0;

        for(auto& num : nums) {
            mx = std::max(mx, num);
            num = gcd(num, mx);
        }

        std::ranges::sort(nums);
        
        for(size_t i = 0, n = nums.size() - 1; i < nums.size() >> 1; ++i) {
            sum += std::gcd(nums[i], nums[n - i]);
        }

        return sum;
    }
};
