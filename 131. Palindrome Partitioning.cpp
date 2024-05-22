class Solution {
private:
    bool isPalindrom(const string& s, int i, int j)
    {
        while(i < j)
            if(s[i++] != s[j--]) return false;

        return true;
    }

    void func(const string& s, vector<string>&& v, const int& k, vector<vector<string>>& answer)
    {        
        if(k == s.size())
        {
            answer.push_back(v);
            return;
        }

        for(int i = k; i < s.size(); ++i)
        {
            if(isPalindrom(s, k, i))
            {
                v.push_back(s.substr(k, i-k+1));
                func(s, move(v), i+1, answer);
                v.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(const string& s) {
        vector<vector<string>> answer{};

        func(s, {}, 0, answer);
        
        return answer;
    }
};
