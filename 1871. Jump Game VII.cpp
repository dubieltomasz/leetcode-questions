class Solution {
public:
    bool canReach(std::string s, const int minJump, const int maxJump) {
        if(s.back() == '1') {
            return false;
        }

        int sum = 0;

        for(size_t i = 1; i < minJump; ++i) {
            s[i] = '1';
        }

        for(size_t i = 0; i <= maxJump - minJump; ++i) {
            sum -= s[i] - '1';
        }

        for(size_t i = maxJump + 1; i < s.size(); ++i) {
            sum -= s[i - minJump] - '1';
            sum += s[i - maxJump - 1] - '1';

            if(sum == 0) {
                s[i] = '1';
            }
        }

        return s[s.size() - 1] == '0';
    }
};
