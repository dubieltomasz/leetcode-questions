class Solution {
private:
    std::vector<int> v;
    void func(TreeNode* node)
    {
        if(node == nullptr) {
            return;
        }

        v.push_back(node->val);
        
        func(node->left);
        func(node->right);
    }

public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        func(root);
        return v;
    }
};
