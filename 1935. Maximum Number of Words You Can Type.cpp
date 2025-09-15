class Solution {
public:
    int canBeTypedWords(const std::string& text, const std::string& brokenLetters) {
        bool isBroken[26] = {};
        bool canBeTyped = true;
        int answer = 0;

        for(const char& letter : brokenLetters) {
            isBroken[letter - 'a'] = true;
        }

        for(const char& character : text) {
            if(character == ' ') {
                canBeTyped ? ++answer : canBeTyped = true;
            } else if(isBroken[character - 'a']) {
                canBeTyped = false;
            }
        }
        
        if(canBeTyped) {
            ++answer;
        }

        return answer;
    }
};
