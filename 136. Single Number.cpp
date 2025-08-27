class Solution {
public:
    int singleNumber(const std::vector<int>& nums) {
        int answer = 0;

        for(const int& num : nums)
            answer ^= num;

        return answer;
    }
};
