class Solution {
public:
    std::vector<bool> prefixesDivBy5(const std::vector<int>& nums) {
        std::vector<bool> answer = {};
        unsigned int number = 0;

        answer.reserve(nums.size());

        for(const int& num : nums) {
            number = ((number << 1) + num) % 5;

            answer.push_back(!number);
        }

        return std::move(answer);
    }
};
