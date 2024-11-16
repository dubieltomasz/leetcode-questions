class Solution {
public:
    std::vector<int> resultsArray(const std::vector<int>& nums, const int k) {
        if(k == 1) return nums;

        int n = nums.size(), i = 1, f = 0;
        std::vector<int> answer;

        answer.reserve(n-k+1);

        while(i < k)
        {
            if(nums[i-1] != nums[i]-1)
                f = k;

            --f;
            ++i;
        }

        answer.push_back(f-- > 0 ? -1 : nums[i-1]);

        while(i < n)
        {
            if(nums[i-1] != nums[i]-1)
            {
                f = k-2;
                answer.push_back(-1);
            }
            else if(f > 0) 
            {
                answer.push_back(-1);
                --f;
            }
            else answer.push_back(nums[i]);

            ++i;
        }

        return answer;
    }
};
