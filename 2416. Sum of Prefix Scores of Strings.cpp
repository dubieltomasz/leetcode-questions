class Solution {
public:
    std::vector<int> sumPrefixScores(const std::vector<std::string>& words) {
        node* tree = new node(0);

        for(const std::string& word : words)
            addNode(tree, word, 0);

        for(const std::string& word : words)
            addScore(tree, word, 0, 0);

        return answer;
    }

private:
    std::vector<int> answer;

    struct node{
        int count;
        node* next[26];

        node(int c)
        {
            count = c;

            for(int i = 0; i < 26; ++i)
                next[i] = nullptr;
        }
    };

    void addNode(node* tree, const std::string& s, int i)
    {
        if(tree->next[s[i]-'a'])
        {
            ++tree->next[s[i]-'a']->count;

            if(i+1 < s.size()) addNode(tree->next[s[i]-'a'], s, i+1);
        }
        else
        {
            tree->next[s[i]-'a'] = new node(1);

            if(i+1 < s.size()) addNode(tree->next[s[i]-'a'], s, i+1);
        }
    }

    void addScore(node* tree, const std::string& s, int i, int score)
    {
        if(i < s.size())
            addScore(tree->next[s[i]-'a'], s, i+1, score+tree->count);
        else answer.push_back(score+tree->count);
    }
};
