class Solution {
public:
    bool judgeSquareSum(const int& c) {
        int a = 0, b = sqrt(c), diff;

        if(a*a == c) return true;

        while(a <= b)
        {
            diff = c - (a*a) - (b*b);

            if(diff == 0) return true;
            else if(diff < 0) --b;
            else ++a;
        }
        
        return false;
    }
};
