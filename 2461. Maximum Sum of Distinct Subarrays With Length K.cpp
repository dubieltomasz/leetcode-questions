class Solution {
public:
    long long maximumSubarraySum(const std::vector<int>& nums, const int k) {
        int duplicates = 0, i = 0, arr[100000] = {};
        long long sum = 0, answer = 0;

        while(i < k)
        {
            sum += nums[i];

            if(++arr[nums[i++]-1] > 1)
                ++duplicates;
        }

        if(!duplicates) answer = sum;

        while(i < nums.size())
        {
            sum -= nums[i-k];

            if(--arr[nums[i-k]-1] > 0)
                --duplicates;

            sum += nums[i];

            if(++arr[nums[i++]-1] > 1)
                ++duplicates;

            if(!duplicates) answer = std::max(answer, sum);
        }

        return answer;
    }
};
