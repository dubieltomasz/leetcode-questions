class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        size_t n = nums.size();
        int i = 0;
        vector<int> answer(n, 1);
        int x = 1;

        while(++i < n)
            answer[i] = answer[i-1] * nums[i-1];
        
        while(--i > 0)
        {
            x *= nums[i];
            answer[i-1] *= x;
        }

        return answer;
    }
};
