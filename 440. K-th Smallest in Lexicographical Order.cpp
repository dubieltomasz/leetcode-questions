class Solution {
public:
    int findKthNumber(long n, int k) {
        int curr = 1, step;
        --k;

        while(k)
        {
            step = countSteps(n, curr, curr+1);

            if(step <= k)
            {
                ++curr;
                k -= step;
            }
            else
            {
                curr *= 10;
                --k;
            }
        }

        return curr;
    }

private:
    int countSteps(long n, long prefix1, long prefix2)
    {
        int steps = 0;

        while(prefix1 <= n)
        {
            steps += std::min(n+1, prefix2) - prefix1;
            
            prefix1 *= 10;
            prefix2 *= 10;
        }

        return steps;
    }
};
