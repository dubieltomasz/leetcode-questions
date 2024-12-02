class Solution {
public:
    int isPrefixOfWord(const std::string& sentence, const std::string& searchWord) {
        std::stringstream stream(sentence);
        std::string str;
        int index = 1, i;

        while(stream >> str)
        {
            i = 0;

            while(i < searchWord.size())
            {
                if(str[i] != searchWord[i])
                    break;

                ++i;
            }

            if(i == searchWord.size())
                return index;

            ++index;
        }

        return -1;
    }
};
