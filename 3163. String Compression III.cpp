class Solution {
public:
    std::string compressedString(const std::string& word) {
        std::string comp = "";
        char c;
        int j;

        for(int i = 0; i < word.size();)
        {
            j = i;
            c = word[i];

            while(j < word.size() && j < i+9 && word[j] == c)
                ++j;

            comp.push_back(j-i+48);
            comp.push_back(c);
            i = j;
        }

        return comp;
    }
};
