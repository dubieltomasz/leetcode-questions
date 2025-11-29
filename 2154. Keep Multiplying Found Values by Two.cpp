class Solution {
public:
    int findFinalValue(const std::vector<int>& nums, int original) {
        bool arr[2000] = {};

        for(const int& num : nums) {
            arr[num-1] = true;

            while(arr[original-1]) {
                original <<= 1;
            }
        }

        return original;
    }
};
