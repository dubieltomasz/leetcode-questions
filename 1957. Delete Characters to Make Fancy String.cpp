class Solution {
public:
    std::string makeFancyString(std::string& s) {
        if(s.size() < 3) return s;

        int i = 2;

        for(int j = 2; j < s.size(); ++j)
            if(s[i-2] != s[j] || s[i-1] != s[j])
                s[i++] = s[j];

        s.resize(i);
        
        return s;
    }
};
