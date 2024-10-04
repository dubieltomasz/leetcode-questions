class Solution {
public:
    long long dividePlayers(const std::vector<int>& skill) {
        long long sum = accumulate(skill.begin(), skill.end(), 0ll), n = skill.size() >> 1, answer = 0ll;
        std::unordered_map<int, int> um;

        if(sum % n) return -1;

        sum /= n;

        for(const int& i : skill)
        {
            if(um.find(i) == um.end())
            {
                answer += 1ll * i * (sum - i);
                ++um[sum-i];
            }
            else if(!--um[i]) um.erase(i);
        }

        return um.empty() ? answer : -1;
    }
};
