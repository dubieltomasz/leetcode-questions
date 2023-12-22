class Solution {
public:
    vector<int> twoSum(vector<int>& nums, const int& target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        for(int i = 1; i < nums.size(); ++i)
            if(nums[i-1] + nums[i] == target)
                return {i-1, i};

        for(int i = 0; i < nums.size()-1; ++i)
            for(int j = i+1; j < nums.size(); ++j)
                if(nums[i] + nums[j] == target)
                    return {i, j};

        return {-1, -1};
    }
};
