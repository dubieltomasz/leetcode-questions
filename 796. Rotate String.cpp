class Solution {
public:
    bool rotateString(const std::string& s, const std::string& goal) {
        if(s.size() != goal.size()) {
            return false;
        }

        int i = 0, j = 0;
        while(i < s.size()) {
            while(i < s.size() && s[i] != goal[j]) {
                ++i;
            }

            for(int tmp = i; j < goal.size() && s[tmp % s.size()] == goal[j]; ++tmp) {
                ++j;
            }

            if(j == goal.size()) {
                return true;
            } else {
                j = 0;
            }

            ++i;
        }

        return false;
    }
};
