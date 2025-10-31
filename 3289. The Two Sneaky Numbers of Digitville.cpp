class Solution {
public:
    const std::vector<int> getSneakyNumbers(const std::vector<int>& nums) {
        bool arr[100] = {};
        int first = -1;

        for(const int& num : nums) {
            if(arr[num]) {
                if(first != -1) {
                    return {first, num};
                } else {
                    first = num;
                }
            } else {
                arr[num] = true;
            }
        }

        return {};
    }
};
