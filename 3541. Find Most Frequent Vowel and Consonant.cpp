class Solution {
public:
    int maxFreqSum(const std::string& s) {
        int arr['z' - 'a' + 1] = {};
        int vowel = 0, consonant = 0;

        for(const char& c : s) {
            ++arr[c - 'a'];
        }

        for(int i = 0; i <= 'z' - 'a'; ++i) {
            switch(i) {
            case 'a' - 'a':
            case 'e' - 'a':
            case 'i' - 'a':
            case 'o' - 'a':
            case 'u' - 'a':
                vowel = std::max(vowel, arr[i]);
                break;
            default:
                consonant = std::max(consonant, arr[i]);
                break;
            }
        }

        return vowel + consonant;
    }
};
