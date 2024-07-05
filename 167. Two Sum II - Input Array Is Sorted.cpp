class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), l, r;

        for(int i = 1; i < n; ++i)
        {
            int a = numbers[i];
            int b = target-a;

            l = 0;
            r = i-1;

            while(l <= r)
            {
                int m = (l+r)/2;

                if(numbers[m] == b) return {m+1, i+1};
                else if(numbers[m] < b) l = m+1;
                else r = m-1;
            }
        }

        return {-1, -1};
    }
};
