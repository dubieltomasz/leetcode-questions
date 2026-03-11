class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) {
            return 1;
        }

        int result = ~n;

        int i = 0;
        while(n) {
            i = (i << 1) | 1;
            n >>= 1;
        }
        
        return result & i;
    }
};
