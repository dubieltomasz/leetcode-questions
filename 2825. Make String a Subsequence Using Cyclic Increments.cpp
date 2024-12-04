class Solution {
public:
    bool canMakeSubsequence(const std::string& str1, const std::string& str2) {
        int j = 0;

        for(int i = 0; i < str1.size(); ++i)
            if((str1[i] == str2[j] || str1[i]+1 == str2[j] || str1[i] == 'z' && str2[j] == 'a') && ++j == str2.size())
                return true;

        return false;
    }
};
