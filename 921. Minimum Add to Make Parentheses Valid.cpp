class Solution {
public:
    int minAddToMakeValid(const std::string& s) {
        int A = 0, B = 0;

        for(const char& c : s)
        {
            if(c == '(') ++A;
            else if(A)   --A;
            else         ++B;
        }

        return A + B;
    }
};
