static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for(int& number : nums)
            sum += number;

        int sum1 = nums.size()*(nums.size()+1)/2;

        int duplicate;

        for(size_t i = 1; i < nums.size(); ++i)
            if(nums[i-1] == nums[i])
            {
                duplicate = nums[i];
                break; 
            }

        return {duplicate, sum1 - sum + duplicate};
    }
};
