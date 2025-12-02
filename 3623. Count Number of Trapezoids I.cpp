class Solution {
public:
    int countTrapezoids(const std::vector<std::vector<int>>& points) {        
        std::unordered_map<int, int> um;
        unsigned long long answer = 0;
        unsigned long long prevPoints = 0;
        constexpr unsigned long long mod = 1e9+7;

        for(const std::vector<int>& point : points) {
            ++um[point[1]];
        }

        for(const std::pair<int, int>& p : um) {
            if(p.second >= 2) {
                unsigned long long tmp = (((unsigned long long)p.second - 1) * p.second) >> 1;
                answer = (answer + (tmp * prevPoints) % mod) % mod;
                prevPoints += tmp;
            }
        }

        return answer;
    }
};
