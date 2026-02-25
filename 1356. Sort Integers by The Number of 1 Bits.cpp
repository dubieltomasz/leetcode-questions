class Solution {
public:
    std::vector<int> sortByBits(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end(),
            [&](const int& a, const int& b) -> bool {
                std::bitset<32> b1(a), b2(b);
                return b1.count() != b2.count() ? b1.count() < b2.count() : a < b;
            }
        );

        return arr;
    }
};
