class Solution {
public:
    int appendCharacters(const string& s, const string& t) {
        int i = 0, j = 0;
        int n1 = s.size(), n2 = t.size();

        while(i < n1 && j < n2)
        {
            if(s[i] == t[j]) ++j;

            ++i;
        }

        return n2-j;
    }
};
