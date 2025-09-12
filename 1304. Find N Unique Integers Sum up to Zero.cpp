class Solution {
public:
    std::vector<int> sumZero(int n) {
        std::vector<int> array(n);

        for(int i = 1; i <= n / 2; ++i) {
            array[i - 1] = -i;
            array[n - i] = i;
        }

        return array;
    }
};
