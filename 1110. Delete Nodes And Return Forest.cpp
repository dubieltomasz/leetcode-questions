class Solution {
public:
    std::vector<TreeNode*> delNodes(TreeNode* root, const std::vector<int>& to_delete) {
        s.insert(to_delete.begin(), to_delete.end());
        
        if(s.find(root->val) == s.end())
            answer.push_back(root);

        func(root);

        return answer;
    }

private:
    std::vector<TreeNode*> answer;
    std::set<int> s;

    bool func(TreeNode* node)
    {
        if(!node) return false;
        else if(s.find(node->val) != s.end())
        {
            if(func(node->left))
                answer.push_back(node->left);

            if(func(node->right))
                answer.push_back(node->right);

            return false;
        }
        else
        {
            if(!func(node->left))
                node->left = nullptr;

            if(!func(node->right))
                node->right = nullptr;

            return true;
        }
    }
};
