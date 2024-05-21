class Solution {
public:
    vector<vector<int>> subsets(const vector<int>& nums) {
        size_t n = nums.size();
        vector<vector<int>> answer{};
        vector<int> tmp(n);

        for(int i = 0; i < pow(2,n); ++i)
        {
            bitset<11> b(i);
            tmp.clear();

            for(int j = 0; j < n; ++j)
                if(b[j]) tmp.push_back(nums[j]);

            answer.push_back(tmp);
        }

        return answer;
    }
};
