static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> um;

        for(int& elem : arr)
            ++um[elem];

        vector<int> occurences{};

        for(auto& x : um)
        {
            for(int& y : occurences)
                if(x.second == y) return false;

            occurences.push_back(x.second);
        }

        return true;
    }
};
