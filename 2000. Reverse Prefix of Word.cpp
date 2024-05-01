class Solution {
public:
    string reversePrefix(string& word, const char& ch) {
        for(size_t i = 0; i < word.size(); ++i)
        {
            if(word[i] == ch)
            {
                for(size_t j = 0; j < i; ++j, --i)
                    swap(word[j], word[i]);

                break;
            }
        }

        return word;
    }
};
