class Solution {
public:
    bool makeEqual(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int characterCount[26]{};
        
        for(string &word : words)
            for(char &character : word)
                ++characterCount[int(character)-97];

        for(int &n : characterCount)
            if(n % words.size() != 0) return false;

        return true;
    }
};
