class Solution {
public:
    int longestSubarray(const std::vector<int>& nums) {
        int left = 0, right = 0, zeros = 0, maxSubarray = 0;

        while(right < nums.size()){
            while(right < nums.size() && zeros < 2){
                if(!nums[right++]) ++zeros;
            }

            maxSubarray = std::max(maxSubarray, right - left - zeros);

            while(zeros == 2){
                if(!nums[left++]) --zeros;
            }
        }

        return maxSubarray == nums.size() ? maxSubarray - 1 : maxSubarray;
    }
};
