class Solution {
public:
    std::string nearestPalindromic(std::string &n) {
        long long num = std::stoll(n), np = nextPalindrom(num), pp = prevPalindrom(num);

        return num-pp <= np-num ? std::to_string(pp) : std::to_string(np);
    }

private:
    long long toPalindrom(std::string s)
    {
        for(int l = 0, r = s.size()-1; l < r; ++l, --r)
            s[r] = s[l];

        return std::stoll(s);
    }

    long long nextPalindrom(long long &num)
    {
        long long left = num, right = 1e18, mid, palindrom, answer;

        while(left <= right)
        {
            mid = left + (right-left)/2;
            palindrom = toPalindrom(std::to_string(mid));

            if(palindrom > num)
            {
                answer = palindrom;
                right = mid-1;
            }
            else left = mid+1;
        }

        return answer;
    }

    long long prevPalindrom(long long &num)
    {
        long long left = 0, right = num, mid, palindrom, answer;

        while(left <= right)
        {
            mid = left + (right-left)/2;
            palindrom = toPalindrom(std::to_string(mid));

            if(palindrom < num)
            {
                answer = palindrom;
                left = mid+1;
            }
            else right = mid-1;
        }

        return answer;
    }
};
