static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    int minSteps(string& s, string& t) {
        int arr[26]{};

        for(char& c : s)
            ++arr[int(c)-97];

        for(char& c : t)
            --arr[int(c)-97];

        int answer = 0;

        for(short i = 0; i < 26; ++i)
            answer += abs(arr[i]);
            
        return answer/2;
    }
};
