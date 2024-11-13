class Solution {
public:
    long long countFairPairs(std::vector<int>& nums, const int lower, const int upper) {
        long long answer = 0;

        std::sort(nums.begin(), nums.end());

        for(int i = 0, j = nums.size()-1; i < j; ++i)
        {
            while(i < j && nums[i] + nums[j] > upper)
                --j;
            
            answer += j-i;
        }

        for(int i = 0, j = nums.size()-1; i < j; ++i)
        {
            while(i < j && nums[i] + nums[j] > lower-1)
                --j;
            
            answer -= j-i;
        }

        return answer;
    }
};
