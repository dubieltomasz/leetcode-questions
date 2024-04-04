static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    int maxDepth(const string& s) {
        int maxDepth = 0, depth = 0;

        for(const char& c : s)
        {
            if(c == '(') ++depth;
            else if(c == ')') --depth;

            if(depth > maxDepth) maxDepth = depth;
        }

        return maxDepth;
    }
};
