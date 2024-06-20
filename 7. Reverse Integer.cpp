class Solution {
public:
    int reverse(int& x) {        
        long answer = 0;

        while(x)
        {
            answer *= 10;
            answer += x % 10;
            x /= 10;
        }

        return (answer < INT_MAX && answer > INT_MIN) ? answer : 0;
    }
};
