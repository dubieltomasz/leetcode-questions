class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        int i = 0, j = 0, answer = 0;
        int arr[128]{};

        while(j < s.size())
        {
            while(j < s.size() && arr[s[j]] == 0)
            {
                ++arr[s[j]];
                ++j;
            }

            answer = max(answer, j-i);

            while(arr[s[j]] != 0)
            {
                --arr[s[i]];
                ++i;
            }
        }

        return answer;
    }
};
