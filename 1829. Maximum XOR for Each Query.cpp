class Solution {
public:
    std::vector<int> getMaximumXor(const std::vector<int>& nums, const int maximumBit) {
        int g = (1 << maximumBit) - 1, tmp = 0, n = nums.size();
        std::vector<int> answer(n);

        for(const int& num : nums)
        {
            tmp ^= num;

            answer[--n] = tmp ^ g;
        }

        return answer;
    }
};
