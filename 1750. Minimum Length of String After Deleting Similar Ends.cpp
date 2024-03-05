class Solution {
public:
    int minimumLength(const string& s) {
        int n = s.size();
        int prefix = 0;
        int suffix = n-1;


        while(prefix < n && -1 < suffix && s[prefix] == s[suffix] && prefix < suffix)
        {
            int tmp1 = prefix, tmp2 = suffix;
            
                while(tmp1 < n && s[prefix] == s[tmp1] && tmp1 <= suffix)
                    ++tmp1;

                while(-1 < tmp2 && s[suffix] == s[tmp2] && tmp2 >= prefix)
                    --tmp2;

                prefix = tmp1;
                suffix = tmp2;
        }

        return (suffix < prefix)? 0 : suffix - prefix + 1;
    }
};
