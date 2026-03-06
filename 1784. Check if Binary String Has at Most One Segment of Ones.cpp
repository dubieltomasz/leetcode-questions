class Solution {
public:
    bool checkOnesSegment(const std::string& s) {
        int index = 0;

        while(index < s.size() && s[index] != '1') {
            ++index;
        }

        while(index < s.size() && s[index] == '1') {
            ++index;
        }

        while(index < s.size() && s[index] != '1') {
            ++index;
        }

        return index == s.size();
    }
};
