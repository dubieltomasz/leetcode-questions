static const void __attribute__((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

class Solution {
public:
    string replaceWords(const vector<string>& dictionary, const string& sentence) {
        string answer = "";
        string word = "";
        bool skip = false;

        set<string> st(dictionary.begin(), dictionary.end());

        for(int i = 0; i < sentence.length(); ++i)
        {
            if(sentence[i] == ' ')
            {
                answer += word + " ";

                word = "";
                skip = false;
            }
            else if(!skip)
            {
                word += sentence[i];

                if(st.find(word) != st.end())
                {
                    answer += word;

                    word = "";
                    skip = true;
                }
            }
        }

        return answer + word;
    }
};
