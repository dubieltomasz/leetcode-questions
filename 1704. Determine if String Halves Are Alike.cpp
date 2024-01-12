static const void __attribute((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int a = 0, b = 0;
        size_t i = 0;

        while(i < s.size()/2)
            if(vowels.find(s[i++]) != vowels.end()) ++a;

        while(i < s.size())
            if(vowels.find(s[i++]) != vowels.end()) ++b;

        return a == b;
    }
};
