class Solution {
public:
    int countBinarySubstrings(const std::string& s) {
        int answer = 0, count = 1, prevCount = 0;

        for(int i = 1; i < s.size(); ++i) {
            if(s[i - 1] == s[i]) {
                ++count;
            } else {
                answer += std::min(prevCount, count);
                prevCount = count;
                count = 1;
            }
        }

        return answer + std::min(prevCount, count);
    }
};
