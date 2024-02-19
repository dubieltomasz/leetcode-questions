class Solution {
public:
    bool isPowerOfTwo(const int& n) {
        if(n <= 0) return false;

        bitset<32> b(n);

        if(b.count() == 1) return true;
        else return false;
    }
};
