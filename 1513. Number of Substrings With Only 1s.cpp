class Solution {
public:
    int numSub(const std::string& s) {
        std::unordered_map<int, int> um;
        int count = 0;
        long answer = 0;

        for(const char& c : s) {
            if(c == '1') {
                ++count;
            } else if(count != 0) {
                ++um[count];
                count = 0;
            }
        }

        ++um[count];

        for(const std::pair<int, int>& p : um) {
            answer = (answer + p.second * (((long)(p.first + 1) * p.first) >> 1)) % 1000000007;
        }

        return answer;
    }
};
