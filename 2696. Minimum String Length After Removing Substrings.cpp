class Solution {
public:
    int minLength(const std::string& s) {
        std::string s2 = " ";
        int n = s.size();

        for(const char& c : s)
        {
            switch(c)
            {
                case 'A':
                    s2 += 'A';
                    break;
                case 'B':
                    if(s2.back() == 'A')
                    {
                        n -= 2;
                        s2.pop_back();
                    }
                    else s2 = " ";
                    break;
                case 'C':
                    s2 += 'C';
                    break;
                case 'D':
                    if(s2.back() == 'C')
                    {
                        n -= 2;
                        s2.pop_back();
                    }
                    else s2 = " ";
                    break;
                default:
                    s2 = " ";
                    break;
            }
        }

        return n;
    }
};
