class Solution {
public:
    int minimumIndex(const std::vector<int>& nums) {
        int dominant = nums[0], countCur = 1, countPre = 0, countPost = 0;

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != dominant)
            {
                if(!--countCur)
                {
                    dominant = nums[i];
                    countCur = 1;
                }
            }
            else ++countCur;            
        }

        for(const int& num : nums)
            if(num == dominant) ++countPost;

        for(int index = 0; index < nums.size() - 1; ++index)
        {
            if(nums[index] == dominant)
            {
                ++countPre;
                --countPost;
            }

            if(countPre > (index + 1 >> 1) && countPost > (nums.size() - 1 - index >> 1))
                return index;
        }

        return -1;
    }
};
