class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(nums.size() == 0) return 0; 
        
        vector<int> arr{nums[0]};

        for(size_t i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > arr.back())
                arr.push_back(nums[i]);
            else
                for(int &num : arr)
                    if(num >= nums[i])
                    {
                        num = nums[i];
                        break;
                    }
        }
        
        return arr.size();
    }
};
