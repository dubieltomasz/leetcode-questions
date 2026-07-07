class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0, sum = 0, i = 1;

        while(n) {
            int digit = n % 10;
            n /= 10;

            if(digit) {
               x += digit * i;
               i *= 10;
            }
            
            sum += digit;
        }

        return x * sum;
    }
};
