class Solution {
public:
    string firstPalindrome(const vector<string>& words) {
        for(const string& word : words)
        {
            size_t i = 0;

            while(i <= word.size()/2)
                if(word[word.size()-i-1] != word[i++]) break;

            if(i > word.size()/2) return word;
        }

        return "";
    }
};
