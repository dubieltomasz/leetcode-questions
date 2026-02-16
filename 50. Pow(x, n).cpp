class Solution {
public:
    double myPow(double x, int n) {
        if(x == -1.0) {
            return n & 1 ? -1.0 : 1.0;
        } else if(x == 1.0 || n == 0) {
            return 1.0;
        } else if(n < -20) { //basically 0
            return 0.0;
        }
        
        double result = 1.0;

        if(n < 0.0) {
            x = 1 / x;
            n = -n;
        }

        do {
            if(n & 1) {
                result *= x;
            }

            x *= x;
        } while(n >>= 1);

        return result;
    }
};
