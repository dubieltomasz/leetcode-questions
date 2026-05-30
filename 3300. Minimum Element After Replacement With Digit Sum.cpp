class Solution {
public:
    int minElement(std::vector<int>& nums) {
        int tmp, minimum = INT_MAX;

        for(auto& num : nums) {
            tmp = 0;

            while(num) {
                tmp += num % 10;
                num /= 10;
            }

            minimum = std::min(minimum, tmp);
        }

        return minimum;
    }
};
