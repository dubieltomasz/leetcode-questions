static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    bool closeStrings(string& word1, string& word2) {
        if(word1.size() != word2.size()) return false;
        else
        {
            int arr1[26]{};
            int arr2[26]{};

            for(char& c : word1)
                ++arr1[int(c)-97];

            for(char& c : word2)
                ++arr2[int(c)-97];

            for(short i = 0; i < 26; ++i)
                if(arr1[i] != 0 && arr2[i] == 0 || arr1[i] == 0 && arr2[i] != 0)
                    return false;

            sort(begin(arr1), end(arr1));
            sort(begin(arr2), end(arr2));

            for(short i = 0; i < 26; ++i)
                if(arr1[i] != arr2[i]) return false;

            return true;
        }
    }
};
