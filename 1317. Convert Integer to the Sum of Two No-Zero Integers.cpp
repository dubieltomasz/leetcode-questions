class Solution {
private:
    bool func(int n)
    {
        while(n % 10) {
            n /= 10;
        }

        return n;
    }

public:
    std::vector<int> getNoZeroIntegers(int n) {
        int a = 1, b = n - 1;

        while(func(b) || func(a)) {
            ++a;
            --b;
        }

        return {a, b};
    }
};
