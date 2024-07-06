class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> answer;
        int l, r, t;

        for(int i = 0; i < nums.size()-2; ++i)
        {
            if(i == 0 || nums[i-1] != nums[i])
            {
                l = i+1;
                r = nums.size()-1;
                t = -nums[i];

                while(l < r)
                {
                    if(nums[l] + nums[r] == t)
                    {
                        answer.push_back({nums[i], nums[l++], nums[r--]});

                        while(l < r && nums[l-1] == nums[l]) ++l;
                        while(l < r && nums[r] == nums[r+1]) --r;
                    }
                    else if(nums[l] + nums[r] < t) ++l;
                    else --r;
                }
            }
        }

        return answer;
    }
};
