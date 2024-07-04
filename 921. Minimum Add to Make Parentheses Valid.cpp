class Solution {
public:
    int minAddToMakeValid(const string& s) {
        int l = 0, r = 0;

        for(const char& c : s)
        {
            switch(c)
            {
                case '(':
                    ++l;
                    break;
                case ')':
                    l? --l : ++r;
                    break;
            }
        }

        return l+r;
    }
};
