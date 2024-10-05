class Solution {
public:
    bool checkInclusion(const std::string& s1, const std::string& s2) {
        if(s1.size() > s2.size()) return false;

        int arr[26] = {0}, n = s1.size();

        for(const char& c : s1)
            ++arr[c-'a'];
        
        for(int i = 0; i < n; ++i)
            --arr[s2[i]-'a'];

        if(func(arr)) return true;
    
        for(int i = n; i < s2.size(); ++i)
        {
            --arr[s2[i]-'a'];
            ++arr[s2[i-n]-'a'];

            if(func(arr)) return true;
        }

        return false;
    }

private:
    bool func(const int* arr)
    {
        for(int i = 0; i < 26; ++i)
            if(arr[i]) return false;
        
        return true;
    }
};
