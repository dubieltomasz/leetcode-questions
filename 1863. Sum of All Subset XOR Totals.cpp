class Solution {
public:
    int subsetXORSum(const vector<int>& nums) {
        int answer = 0;

        for(const int& i : nums)
            answer |= i;

        return answer * pow(2,nums.size()-1);
    }
};
