class Solution {
public:
    int maxWidthRamp(const std::vector<int>& nums) {
        int maxWith = 0;
        std::stack<int> indicesStack;

        indicesStack.push(0);

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[indicesStack.top()] > nums[i])
                indicesStack.push(i);
        }

        for(int i = nums.size()-1; !indicesStack.empty() && i >= 0; --i)
        {
            while(!indicesStack.empty() && nums[indicesStack.top()] <= nums[i])
            {
                maxWith = std::max(maxWith, i - indicesStack.top());
                indicesStack.pop();
            }
        }

        return maxWith;
    }
};
