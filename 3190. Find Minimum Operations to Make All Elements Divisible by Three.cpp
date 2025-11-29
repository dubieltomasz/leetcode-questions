class Solution {
public:
    int minimumOperations(const std::vector<int>& nums) {
        int answer = 0;

        for(const int& num : nums) {
            answer += num % 3 != 0;
        }

        return std::move(answer);
    }
};
