class Solution {
private:
    void add(TreeNode* node, const int& val, const int& d, int cd)
    {
        if(d == cd)
        {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
        }
        else
        {
            if(node->left) add(node->left, val, d, cd+1);
            if(node->right) add(node->right, val, d, cd+1);
        }
    }

public:
    TreeNode* addOneRow(TreeNode* root, const int& val, const int& depth) {
        if(depth == 1) root = new TreeNode(val, root, nullptr);
        else add(root, val, depth, 2);
        
        return root;
    }
};
