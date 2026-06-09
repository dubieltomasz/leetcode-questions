class Solution {
public:
    long long maxTotalValue(const std::vector<int>& nums, const int k) {
        int maximum = INT_MIN, minimum = INT_MAX;

        for(const auto& num : nums) {
            maximum = std::max(maximum, num);
            minimum = std::min(minimum, num);
        }

        return static_cast<long long>(maximum - minimum) * k;
    }
};
