class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        ranges::sort(nums);
        size_t size = nums.size();
        
        vector<int> dividersAmount(size, 1);
        vector<int> lastDividersIndex(size, -1);

        int maxDividersIndex = 0;

        for(int i = 1; i < size; ++i)
        {
            for(int j = 0; j < i; ++j)
                if(nums[i] % nums[j] == 0)
                    if(dividersAmount[i] < dividersAmount[j] + 1)
                    {
                        dividersAmount[i] = dividersAmount[j] + 1;
                        lastDividersIndex[i] = j;
                    }

            if(dividersAmount[maxDividersIndex] < dividersAmount[i])
                maxDividersIndex = i;
        }

        vector<int> answer{};

        while(maxDividersIndex >= 0)
        {
            answer.push_back(nums[maxDividersIndex]);
            maxDividersIndex = lastDividersIndex[maxDividersIndex];
        }

        return answer;
    }
};
