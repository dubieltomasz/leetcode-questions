class Solution {
public:
    int binaryGap(int n) {
        int maxDistance = 0, length = 0;

        while(!(n & 1)) {
            n >>= 1;
        }

        while(n) {
            if(n & 1) {
                maxDistance = std::max(maxDistance, length);
                length = 0;
            }

            ++length;
            n >>= 1;
        }

        return maxDistance;
    }
};
