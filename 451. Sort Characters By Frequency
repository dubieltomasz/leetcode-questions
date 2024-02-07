class Solution {
public:
    string frequencySort(string& s) {
        unordered_map<char, int> um;

        for(const char& c : s)
            ++um[c];

        vector<pair<char, int>> v(um.begin(), um.end());

        sort(begin(v), end(v), [](const pair<char, int>& a, const pair<char, int>& b)
        {
            return a.second > b.second;
        });
    
        s = "";

        for(pair<char, int>& element : v) 
            while(element.second--)
                s += element.first;

        return s;
    }
};
