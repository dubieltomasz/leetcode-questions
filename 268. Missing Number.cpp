class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int n = nums.size();

        int sum = (n+1)*n/2;

        for(const int& num : nums)
            sum -= num;

        return sum;
    }
};
