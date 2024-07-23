class Solution {
public:
    std::vector<int> frequencySort(const std::vector<int>& nums) {
        std::unordered_map<int, int> um;
        std::vector<std::pair<int ,int>> v;
        std::vector<int> answer; answer.reserve(nums.size());

        for(const int& num : nums)
            ++um[num];
        
        for(const std::pair<int, int>& p : um)
            v.push_back({p.second, p.first});
        
        std::sort(v.begin(), v.end(), [&](const pair<int, int>& a, const pair<int, int>& b)->bool { return (a.first != b.first) ? a.first < b.first : a.second > b.second; });

        for(const std::pair<int, int>& p : v)
            for(int i = 0; i < p.first; ++i)
                answer.push_back(p.second);

        return answer;
    }
};
