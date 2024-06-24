class Solution {
public:
    int fib(const int& n) {
        return ((1/sqrt(5)) * (pow((1+sqrt(5))/2, n) - pow((1-sqrt(5))/2, n)));
    }
};
