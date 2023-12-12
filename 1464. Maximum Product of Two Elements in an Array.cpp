class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int a{}, b{};

        for(unsigned int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > a)
            {
                b = a;
                a = nums[i];
            }
            else if(nums[i] > b)
                b = nums[i];
        }

        return (a-1)*(b-1);
    }
};
