class Solution {
public:
    int minOperations(const std::vector<int>& nums, int k) {
        return std::move(std::accumulate(nums.begin(), nums.end(), 0) % k);
    }
};
