class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        for(size_t i = 0; i < strs[0].size(); ++i)
            for(size_t j = 1; j < strs.size(); ++j)
                if(strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);

        return strs[0];
    }
};
