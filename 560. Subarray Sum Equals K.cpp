class Solution {
public:
    int subarraySum(const std::vector<int>& nums, const int& k) {
        std::unordered_map<int, int> um;
        int n = nums.size(), answer = 0;
        std::vector<int> v(n);

        v[0] = nums[0];
        
        for(size_t i = 1; i < n; ++i)
            v[i] = v[i-1] + nums[i];

        for(const int& i : v)
        {
            if(i == k)
                ++answer;
            
            if(um.find(i-k) != um.end())
                answer += um[i-k];
        
            ++um[i];
        }

        return answer;
    }
};
