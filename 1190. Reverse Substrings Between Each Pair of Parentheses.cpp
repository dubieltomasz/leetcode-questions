class Solution {
public:
    std::string reverseParentheses(const std::string& s) {
        std::string answer;
        int n = s.size(), l = 0, r = n-1;

        while(l < n)
        {
            if(s[l] == '(')
            {
                r = l+1;
                int x = 1;

                while(x)
                {
                    if(s[r] == '(') ++x;
                    else if(s[r] == ')') --x;

                    ++r;
                }

                std::string mid = reverseParentheses(s.substr(l+1, r-l-2));
                reverse(mid.begin(), mid.end());

                answer += mid;

                l = r-1;
            }
            else answer += s[l];

            ++l;
        }        

        return answer;
    }
};
