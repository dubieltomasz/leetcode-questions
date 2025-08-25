class Solution {
public:
    std::string largestGoodInteger(const std::string& num) {
        char digit = '\0';
        
        for(int i = 0; i < num.size()-2; ++i){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                digit = std::max(digit, num[i]);
                i += 2;
            }
        }

        return digit ? std::string(3, digit) : "";
    }
};
