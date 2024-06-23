class Solution {
public:
    int searchInsert(const vector<int>& nums, const int& target) {
        int l = 0, r = nums.size()-1, m;

        while(l <= r)
        {
            m = (l+r)/2;

            if(nums[m] == target) return m;
            else if(nums[m] >= target) r = m-1;
            else l = m+1;
        }

        return l;
    }
};
