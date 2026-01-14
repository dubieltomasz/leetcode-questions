class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::unordered_set<std::string> us = {"()"};

        while(--n) {
            std::unordered_set<std::string> tmpUs = {};

            for(const std::string& str : us) {
                std::string tmpStr(str.size() + 2, ' ');

                for(int i = 0; i <= str.size(); i++) {
                    for(int j = 0; j < i; j++) {
                        tmpStr[j] = str[j];
                    }

                    tmpStr[i] = '(';
                    tmpStr[i + 1] = ')';

                    for(int j = i + 2; j < str.size() + 2; j++) {
                        tmpStr[j] = str[j - 2];
                    }
                    
                    tmpUs.insert(tmpStr);
                }
            }

            us = std::move(tmpUs);
        }

        return std::vector<std::string>(us.begin(), us.end());
    }
};
