class Solution {
public:
    long long minEnd(int n, const int x) {
        long long answer = x;

        while(--n)
        {
            ++answer |= x;
        }
        
        return answer;
    }
};
