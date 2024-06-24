class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        func(root);

        return root;
    }

private:
    void func(TreeNode* node)
    {
        if(!node) return;

        swap(node->left, node->right);

        func(node->left);
        func(node->right);
    }
};
