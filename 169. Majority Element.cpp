class Solution {
public:
    int majorityElement(vector<int>& nums) {
        ranges::sort(nums);
        
        int arr[2] = {0,0};
        
        for(const int& n : nums)
        {
            if(n == arr[0]) ++arr[1];
            else
            {
                arr[0] = n;
                arr[1] = 1;
            }

            if(arr[1] > nums.size()/2) return arr[0];
        }

        return 0;
    }
};
