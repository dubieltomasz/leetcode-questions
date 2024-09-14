class Solution {
public:
    int longestSubarray(const std::vector<int>& nums) {
        int answer = 0, current = 0, k = 0;

        for(const int& num : nums)
        {
            if(k < num)
            {
                k = num;
                answer = 1;
                current = 1;
            }
            else if(k == num) answer = std::max(answer, ++current);
            else current = 0;
        }

        return answer;
    }
};
