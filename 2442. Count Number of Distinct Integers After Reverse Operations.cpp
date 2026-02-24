class Solution {
public:
    int countDistinctIntegers(const std::vector<int>& nums) {
        std::unordered_set<int> us = {};

        for(int num : nums) {
            us.insert(num);

            int tmp = 0;
            while(num > 0) {
                tmp = (tmp * 10) + num % 10;
                num /= 10;
            }

            us.insert(tmp);
        }

        return us.size();
    }
};
