class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = -1;

        for(int i = 0; i < s.length(); ++i)
        {
            int j = i, m = -1;

            while(++j < s.length())
                if(s[i] == s[j]) m = j-i-1;

            if(m > n) n = m;
        }

        return n;
    }
};
