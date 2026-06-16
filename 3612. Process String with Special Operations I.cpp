class Solution {
public:
    std::string processStr(const std::string& s) {
        std::string result = "";
        result.reserve(s.size());

        for(const auto& c : s) {
            switch(c) {
                case '*':
                    if(!result.empty()) {
                        result.pop_back();
                    }
                    break;
                case '#':
                    result += result;
                    break;
                case '%':
                    std::ranges::reverse(result);
                    break;
                default:
                    result += c;
            }
        }

        return result;
    }
};
