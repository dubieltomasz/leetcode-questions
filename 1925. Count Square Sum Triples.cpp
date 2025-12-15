class Solution {
public:
    int countTriples(int n) {
        int answer = 0;

        while(n) {
            for(int i = 1; i < n; ++i) {
                double j = std::sqrt(n * n - i * i);

                if(j && j == (int) j) {
                    ++answer;
                }
            }

            --n;
        }

        return answer;
    }
};
