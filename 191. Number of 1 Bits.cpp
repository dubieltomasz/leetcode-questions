class Solution {
public:
    int hammingWeight(int& n) {
        int answer = 1;

        while(n > 1)
        {
            answer += n & 1;
            n >>= 1;
        }

        return answer;
    }
};
