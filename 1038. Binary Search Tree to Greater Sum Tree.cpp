class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        func(root, 0);

        return root;
    }

private:
    int func(TreeNode* node, const int& x)
    {
        if(!node) return x;

        node->val += func(node->right, x);

        return func(node->left, node->val);
    }
};
