class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        unsigned short a{}, b{}, c = INT_MAX, d = INT_MAX;

        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > a)
            {
                b = a;
                a = nums[i];
            }
            else if(nums[i] > b)
                b = nums[i];

            if(nums[i] < c)
            {
                d = c;
                c = nums[i];
            }
            else if(nums[i] < d)
                d = nums[i];
        }

        return a*b - c*d;
    }
};
