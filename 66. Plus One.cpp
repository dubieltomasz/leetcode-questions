class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        bool carry = true;

        for(int n = digits.size()-1; carry && n >= 0; --n)
        {
            if(digits[n] != 9)
            {
                ++digits[n];
                carry = false;
            }
            else
            {
                digits[n] = 0;
            }
        }

        if(carry) digits.insert(digits.begin(), 1);

        return digits;
    }
};
