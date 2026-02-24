class Solution {
public:
    inline std::string smallestString(std::string& s) {
        int i = 0;

        #pragma unroll
        while(i < s.size() && s[i] == 'a') {
            ++i;
        }

        if(i == s.size()) {
            s[i - 1] = 'z';
        }

        #pragma unroll
        while(i < s.size() && s[i] != 'a') {
            --s[i++];
        }

        return s;
    }
};
