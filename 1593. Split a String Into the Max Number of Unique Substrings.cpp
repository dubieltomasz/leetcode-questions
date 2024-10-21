class Solution {
public:
    int maxUniqueSplit(const std::string& s) {
        S = s;
        n = s.size();

        func(0, 0);

        return answer;
    }

private:
    std::set<std::string> uniqueSubstrings;
    std::string S;
    int n, answer = 0;

    void func(int idx, int count)
    {
        if(idx == n) answer = std::max(answer, count);
        else if(count + n-idx > answer)
        {
            for(int i = 1; i < n-idx+1; ++i)
            {
                std::string tmp = S.substr(idx, i);
                
                if(uniqueSubstrings.find(tmp) == uniqueSubstrings.end())
                {
                    uniqueSubstrings.insert(tmp);
                    func(idx+i, count+1);
                    uniqueSubstrings.erase(tmp);
                }
            }
        }
    }
};
