class Solution {
public:
    bool isPalindrome(const string& s) {
        for(int i = 0, j = s.size()-1; i < j; ++i, --j)
        {
            if(s[i] < '0' || s[i] > '9' && s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')
                ++j;
            else if(s[j] < '0' || s[j] > '9' && s[j] < 'A' || s[j] > 'Z' && s[j] < 'a' || s[j] > 'z')
                --i;
            else if('0' <= s[i] && s[i] <= '9' || '0' <= s[j] && s[j] <= '9')
            {
                if(s[i] != s[j]) return false;
            }
            else if(s[i] - s[j] != 0 && abs(s[i]-s[j]) != 32)
                return false;
        }

        return true;
    }
};
