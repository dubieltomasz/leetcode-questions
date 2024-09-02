class Solution {
public:
    int chalkReplacer(const std::vector<int>& chalk, int k) {
        int sum = 0, i;

        for(i = 0; i < chalk.size(); ++i)
        {
            if((k -= chalk[i]) < 0) return i;

            sum += chalk[i];
        }

        k %= sum;
        i = 0;

        while(k >= chalk[i])
            k -= chalk[i++];

        return i;
    }
};
