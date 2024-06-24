class Solution {
public:
    bool isAnagram(const string& s, const string& t) {
        int arr[26] = {};

        for(const char& c : s)
            ++arr[int(c)-'a'];

        for(const char& c : t)
            --arr[int(c)-'a'];

        for(int i = 0; i < 25; ++i)
            if(arr[i]) return false;
        
        return true;
    }
};
