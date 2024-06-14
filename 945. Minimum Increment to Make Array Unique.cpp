class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int answer = 0;

        for(int r = nums[0], i = 1; i < nums.size(); ++i)
        {
            if(r >= nums[i])
            {
                answer += r-nums[i]+1;
                nums[i] += r-nums[i]+1;
            }

            r = nums[i];
        }

        return answer;
    }
};
