class Solution {
public:
    int smallestDistancePair(std::vector<int>& nums, const int k) {
        std::sort(nums.begin(), nums.end());

        int left = 0, right = nums.back(), mid;    

        while(left < right)
        {
            mid = (left + right)/2;
            
            func(nums, mid) < k ? left = mid+1 : right = mid;
        }

        return left;
    }

private:
    int func(const std::vector<int>& nums, const int& maxDistance)
    {
        int left = 0, count = 0;

        for(int right = 0; right < nums.size(); ++right)
        {
            while(nums[right] - nums[left] > maxDistance)
                ++left;

            count += right - left;
        }

        return count;
    }
};
