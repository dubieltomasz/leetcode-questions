class Solution {
private:
    inline int msbPlus1(int n) {
        int i = 0;

        while(n) {
            n >>= 1;
            ++i;
        }

        return i;
    }

public:
    int uniqueXorTriplets(const std::vector<int>& nums) {
        return nums.size() <= 2 ? nums.size() : 1 << msbPlus1(nums.size());
    }
};
