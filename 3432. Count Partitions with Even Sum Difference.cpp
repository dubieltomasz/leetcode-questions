class Solution {
public:
    int countPartitions(const std::vector<int>& nums) {
        return std::move(std::accumulate(nums.begin(), nums.end(), 0) & 1 ? 0 : nums.size() - 1);
    }
};
