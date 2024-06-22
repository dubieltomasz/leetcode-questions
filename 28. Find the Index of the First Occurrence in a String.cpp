class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        if(needle.size() > haystack.size()) return -1;
        
        for(int i = 0; i < haystack.size()-needle.size()+1; ++i)
        {
            int j = 0, ii = i;

            while(j < needle.size() && needle[j] == haystack[ii])
            {
                ++j;
                ++ii;
            }

            if(j == needle.size()) return i;
        }

        return -1;
    }
};
