class Solution {
public:
    int sumFourDivisors(const std::vector<int>& nums) {
        int sum = 0;

        for(const int& num : nums) {
            int divisor = 0, i = 2;
            float sqrt = std::sqrt(num);

            while(i < sqrt) {
                if(num % i == 0) {
                    if(divisor == 0) {
                        divisor = i;
                    } else {
                        break;
                    }
                }

                ++i;
            }

            if(divisor && i > sqrt) {
                sum += 1 + num + divisor + (num / divisor);
            }
        }

        return sum;
    }
};
