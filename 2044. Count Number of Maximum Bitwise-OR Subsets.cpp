class Solution {
public:
    int countMaxOrSubsets(const std::vector<int>& nums) {
        int curOr, maxOr = 0, count = 0;

        for(const int& num : nums)
            maxOr |= num;

        for(int i = 1; i < 1 << nums.size(); ++i)
        {
            std::bitset<32> b(i);
            curOr = 0;

            for(int j = 0; j < 32; ++j)
                if(b[j]) curOr |= nums[j];
            
            if(curOr == maxOr) ++count;
        }

        return count;
    }
};
