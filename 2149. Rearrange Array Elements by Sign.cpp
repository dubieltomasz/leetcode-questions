class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int> negative;

        for(const int& num : nums)
        {
            if(num > 0) positive.push_back(num);
            else negative.push_back(num);
        }

        for(size_t i = 0; i < nums.size(); ++i)
        {
            if(i % 2 == 0) nums[i] = positive[i/2];
            else nums[i] = negative[i/2];
        }

        return nums;
    }
};
