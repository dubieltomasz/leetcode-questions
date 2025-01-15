class Solution {
public:
    std::string removeOuterParentheses(const std::string& s) {
        std::string answer = "";
        int countOpeningPar = 0;

        for(const char& c : s)
        {
            if(c == '(') ++countOpeningPar;
            else --countOpeningPar;

            if(countOpeningPar > 1 || countOpeningPar == 1 && c == ')')
                answer += c;
        }

        return answer;
    }
};
