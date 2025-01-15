class Solution {
public:
    int minimizeXor(const int& num1, int num2) {
        int countBits = 0, x = 0;

        while(num2)
        {
            countBits += num2 & 1;
            num2 >>= 1;
        }

        for(int i = 31; i >= 0 && countBits; --i)
        {
            if(num1 & (1 << i))
            {
                x |= (1 << i);
                --countBits;
            }
        }
        
        for(int i = 0; countBits; ++i)
        {
            if(!(x & (1 << i)))
            {
                x |= (1 << i);
                --countBits;
            }
        }

        return x;
    }
};
