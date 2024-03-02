class Solution {
public:
    vector<int> sortedSquares(const vector<int>& nums) {
        int size = nums.size();
        int left = 0;
        int right = size-1;
        vector<int> answer(size);

        for(int i = size-1; i >= 0; --i)
        {
            if(abs(nums[left]) >= abs(nums[right]))
            {
                answer[i] = nums[left] * nums[left];
                ++left;
            }
            else
            {
                answer[i] = nums[right] * nums[right];
                --right;
            }
        }

        return answer;
    }
};
