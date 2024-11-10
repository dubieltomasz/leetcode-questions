class Solution {
public:
    int minimumSubarrayLength(const std::vector<int>& nums, const int k) {
        int answer = INT_MAX, valueOR = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            valueOR |= nums[i];

            if(valueOR >= k)
            {
                int j = i;
                valueOR = nums[i];

                while(valueOR < k)
                    valueOR |= nums[--j];

                answer = std::min(answer, i-j+1);
                valueOR = 0;
                i = j;
            }
        }

        return answer != INT_MAX ? answer : -1;
    }
};
