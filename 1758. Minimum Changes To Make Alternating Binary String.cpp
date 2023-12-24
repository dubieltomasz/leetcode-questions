class Solution {
public:
    int minOperations(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n{};

        for(int i = 0; i < s.size(); ++i)
            if(i % 2 == 0)
            {
                if(s[i] == '0') ++n;
            }
            else
            {
                if(s[i] == '1') ++n;
            }

        return (n<s.size()-n)? n : s.size()-n;
    }
};
