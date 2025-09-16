class Solution {
private:
    struct node {
        node *letters['z' - 'a' + 1] = {};
    };

public:
    std::vector<std::string> partitionString(const std::string& s) {
        std::vector<std::string> answer;
        node *root = new node(), *treeNode = root;
        std::string tmp;

        tmp.reserve(s.size() >> 1);

        for(const char& c : s) {
            tmp.push_back(c);

            if(treeNode->letters[c - 'a'] == nullptr){
                treeNode->letters[c - 'a'] = new node();
                treeNode = root;
                answer.push_back(tmp);
                tmp.clear();
            } else {
                treeNode = treeNode->letters[c - 'a'];
            }
        }
        
        return answer;
    }
};
