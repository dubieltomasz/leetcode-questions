class Solution {
private:
    int reverse(int n) {
        int result = 0;

        while(n) {
            result *= 10;
            result += n % 10;
            n /= 10;
        }

        return result;
    }

public:
    inline int mirrorDistance(int n) {
        return std::abs(n - reverse(n));
    }
};
