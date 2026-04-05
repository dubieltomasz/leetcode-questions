class Solution {
public:
    bool checkStrings(const std::string& s1, const std::string& s2) {
        std::array<std::array<int, 'z'-'a'+1>, 2> arr = {};
        bool toggle = 0;

        for(const char& c : s1) {
            ++(arr[toggle])[c - 'a'];
            toggle = !toggle;
        }

        toggle = 0;

        for(const char& c : s2) {
            --(arr[toggle])[c - 'a'];
            toggle = !toggle;
        }

        for(size_t i = 0; i < 'z'-'a'+1; ++i) {
            if(arr[0][i] || arr[1][i]) {
                return false;
            }
        }

        return true;
    }
};
