class Solution {
public:
    long long zeroFilledSubarray(const std::vector<int>& nums)
    {
        long long answer = 0, n = 0;

        for(int i = 0; i < nums.size(); ++i) {
            while(i < nums.size() && nums[i] != 0)
                ++i;

            n = i;

            while(i < nums.size() && nums[i] == 0)
                ++i;

            answer += (i - n) * (i - n + 1) >> 1;
        }

        return answer;
    }
};
