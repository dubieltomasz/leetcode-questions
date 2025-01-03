class Solution {
public:
    int waysToSplitArray(std::vector<int>& nums) {
        long long sum1 = std::accumulate(nums.begin(), nums.end(), 0ll), sum2 = 0;
        int answer = 0;

        for(int i = 0; i < nums.size()-1; ++i)
            answer += ((sum2 += nums[i]) >= (sum1 -= nums[i]));

        return answer;
    }
};
