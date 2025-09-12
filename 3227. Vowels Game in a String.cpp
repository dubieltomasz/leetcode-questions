class Solution {
public:
    bool doesAliceWin(const std::string& s) {
        for(const char& c : s) {
            switch(c) {
            case 'a' :
            case 'e' :
            case 'i' :
            case 'o' :
            case 'u' :
                return true;
            }
        }

        return false;
    }
};
