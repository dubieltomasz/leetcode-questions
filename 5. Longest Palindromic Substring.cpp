class Solution {
public:
    std::string longestPalindrome(const std::string& s) {
        if(s.size() < 2) return s;

        int answerL = 0, answerI = 0, currL;

        for(int i = 0; i < s.size(); ++i)
        {
            currL = std::max(palindromLength(s, i, i+1), palindromLength(s, i, i));

            if(currL > answerL)
            {
                answerL = currL;
                answerI = i - (currL-1)/2;
            }
        }

        return s.substr(answerI, answerL);
    }

private:
    int palindromLength(const std::string& s, int l, int r)
    {
        while(l > -1 && r < s.size() && s[l] == s[r])
        {
            --l;
            ++r;
        }

        return r-l-1;
    }
};
