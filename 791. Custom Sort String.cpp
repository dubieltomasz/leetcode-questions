class Solution {
public:
    string customSortString(const string order, const string s) {
        int arr[26]{};
        string answer = "";

        for(const char& c : s)
            ++arr[int(c)-97];

        for(const char& c : order)
            while(arr[int(c)-97]-- > 0)
                answer += c;

        for(int i = 0; i < 26; ++i)
            while(arr[i]-- > 0)
                answer += char(i+97);

        return answer;
    }
};
