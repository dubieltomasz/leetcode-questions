class Solution {
public:
    int rangeBitwiseAnd(const int& left, const int& right) {
        bitset<31> bl(left);
        bitset<31> br(right);

        int answer = 0;

        for(int i = 31; bl[i] == br[i] && i >= 0; --i)
            answer += bl[i] * pow(2,i);

        return answer;
    }
};
