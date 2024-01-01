class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        sort(begin(g), end(g));
        sort(begin(s), end(s));

        int n = 0, i = -1, j = -1;

        while(++i < g.size() && ++j < s.size())
        {
            if(g[i] <= s[j]) ++n;
            else --i;
        }

        return n;
    }
};
