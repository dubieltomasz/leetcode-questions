class Solution {
public:
    std::vector<std::string> validateCoupons(const std::vector<std::string>& code, const std::vector<std::string>& businessLine, const std::vector<bool>& isActive) {
        std::unordered_map<std::string, std::vector<std::string>> um;
        std::vector<std::string> validCoupons = {};
        validCoupons.reserve(code.size());

        for(int i = 0; i < code.size(); ++i) {
            if(!isActive[i]) {
                continue;
            }

            if(code[i] == "") {
                continue;
            }

            bool ok = true;
            for(const char& c : code[i]) {
                if((c < '0'
                || '9' < c && c < 'A'
                || 'Z' < c && c < 'a'
                || 'z' < c) && c != '_') {
                    ok = false;
                    break;
                }
            }

            if(!ok) {
                continue;
            }

            um[businessLine[i]].push_back(code[i]);
        }

        std::sort(um["electronics"].begin(), um["electronics"].end());
        validCoupons.insert(validCoupons.end(), um["electronics"].begin(), um["electronics"].end());

        std::sort(um["grocery"].begin(), um["grocery"].end());
        validCoupons.insert(validCoupons.end(), um["grocery"].begin(), um["grocery"].end());

        std::sort(um["pharmacy"].begin(), um["pharmacy"].end());
        validCoupons.insert(validCoupons.end(), um["pharmacy"].begin(), um["pharmacy"].end());

        std::sort(um["restaurant"].begin(), um["restaurant"].end());
        validCoupons.insert(validCoupons.end(), um["restaurant"].begin(), um["restaurant"].end());

        return std::move(validCoupons);
    }
};
