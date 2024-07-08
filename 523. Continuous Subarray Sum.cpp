class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        if(n < 2) return false;

        int sum = 0;
        unordered_map<int, int> mp;

        for(size_t i = 0; i < n; ++i)
        {
            sum += nums[i];

            if(sum != 0 && sum % k == 0 && i > 0|| mp.find(sum % k) != mp.end() && mp[sum % k] != i-1) return true;
            else if(mp.find(sum % k) == mp.end()) mp[sum % k] = i;
        }

        return sum == k || sum == 0;
    }
};
