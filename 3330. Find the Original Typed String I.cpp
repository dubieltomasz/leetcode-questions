class Solution {
public:
    int possibleStringCount(const std::string& word) {
        int possibilities = 1;

        for(int i = 1; i < word.size(); ++i) {
            if(word[i-1] == word[i]) {
                ++possibilities;
            }
        }

        return possibilities;
    }
};
