class Solution {
public:
    bool canBeEqual(const std::string& s1, const std::string& s2) {
        for(size_t i = 0; i < 2; ++i) {
            if((s1[i] == s2[i] && s1[i + 2] == s2[i + 2]) || (s1[i] == s2[i + 2] && s1[i + 2] == s2[i])) {
                continue;
            } else return false;
        }

        return true;
    }
};
