class Solution {
public:
    int findComplement(int num) {
        int answer = num, mask = 1;

        while(num)
        {
            answer ^= mask;
            mask <<= 1;
            num >>= 1;
        }

        return answer;
    }
};
