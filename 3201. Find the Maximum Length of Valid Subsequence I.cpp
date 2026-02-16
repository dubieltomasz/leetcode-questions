class Solution {
public:
    int maximumLength(const std::vector<int>& nums) {
        int countOdd = 0, countEven = 0, thirdCounter = 0; // odd->even->odd or reverse
        bool wasLastOdd = !(nums.front() & 1);

        for(const int& num : nums) {
            num & 1 ? ++countOdd : ++countEven;
            
            if((num & 1) != wasLastOdd) {
                wasLastOdd = !wasLastOdd;
                ++thirdCounter;
            }
        }

        return std::max({countOdd, countEven, thirdCounter});
    }
};
