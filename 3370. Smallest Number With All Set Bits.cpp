class Solution {
public:
    int smallestNumber(const int n) {
        int x = 0;

        while(x < n) {
            x <<= 1;
            x |= 1;
        }

        return x;
    }
};
