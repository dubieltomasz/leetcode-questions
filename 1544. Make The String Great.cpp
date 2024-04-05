static  const void __attribute((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    string makeGood(const string& s) {
        string answer = "";
        
        for(int i = 0; i < s.size(); ++i)
        {
            if(answer != "" && (int(s[i]) == int(answer.back())-32 || int(s[i])-32 == int(answer.back())))
                answer.pop_back();
            else
                answer.push_back(s[i]);
        }

        return answer;
    }
};
