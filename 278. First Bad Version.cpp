class Solution {
public:
    int firstBadVersion(int n) {
        int m = 1, v;

        while(m <= n)
        {
            v = m+(n-m)/2;

            isBadVersion(v) ? n = v-1 : m = v+1;
        }

        return m;
    }
};
