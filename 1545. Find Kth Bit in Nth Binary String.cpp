class Solution {
public:
    char findKthBit(const int n, const int k) {
        return '0' + ((k / (k & -k) >> 1 & 1) ? k & 1 : !(k & 1));
    }
};
