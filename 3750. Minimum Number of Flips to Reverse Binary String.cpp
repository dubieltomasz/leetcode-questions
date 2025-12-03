class Solution {
public:
    int minimumFlips(int n) {
        int answer = 0, n1 = n, n2 = 0;

        while(n1) {
            n2 <<= 1;
            n2 += n1 & 1;
            n1 >>= 1;
        }

        while(n) {
            answer += (n & 1) != (n2 & 1);
            n >>= 1;
            n2 >>= 1;
        }

        return answer;
    }
};
