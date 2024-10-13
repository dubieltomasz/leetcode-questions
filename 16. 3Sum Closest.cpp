class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, const int& target) {
        if(nums.size() == 3) return nums[0] + nums[1] + nums[2];

        int n = nums.size();

        std::sort(nums.begin(), nums.end());

        if(nums[0] + nums[1] + nums[2] > target)
            return nums[0] + nums[1] + nums[2];
        else if(nums[n-3] + nums[n-2] + nums[n-1] < target)
            return nums[n-3] + nums[n-2] + nums[n-1];

        int answer = target ^ INT_MAX, l, r, sum;

        for(int i = 0; i < n; ++i)
        {
            l = i+1;
            r = nums.size()-1;

            while(l < r)
            {
                sum = nums[i] + nums[l] + nums[r];

                if(std::abs(target - sum) < std::abs(target - answer))
                    answer = sum;
                else if(sum == target)
                    return sum;
                
                if(sum < target)
                {
                    while(l < r && nums[l] == nums[l+1])
                        ++l;
                    
                    ++l;
                }
                else
                {
                    while(l < r && nums[r-1] == nums[r])
                        --r;

                    --r;
                }
            }
        }

        return answer;
    }
};
