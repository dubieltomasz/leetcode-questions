class Solution {
public:
    int findClosest(int x, int y, int z) {
        x = std::abs(x - z);
        y = std::abs(y - z);

        if(x == y) return 0;
        else return x < y ? 1 : 2;
    }
};
