class Solution {
public:
    bool isPalindrome(int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if(x < 0) return false;
        
        int xp = x;
        unsigned int y = 0;

        while(xp != 0)
        {
            y = y * 10 + xp % 10;
            xp /= 10;
        }

        return x == y;
    }
};
