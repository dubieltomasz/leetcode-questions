class Solution {
public:
    int lengthOfLastWord(const std::string& s) {
        int n = s.size()-1, i;

        while(s[n] == ' ')
            --n;

        i = n;

        while(i >= 0 && s[i] != ' ')
            --i;
        
        return n-i;
    }
};
