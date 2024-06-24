class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return func(root->left, root->right);
    }

private:
    bool func(TreeNode* node1, TreeNode* node2)
    {
        if(!node1 && !node2) return true;
        else if(!node1 || !node2 || node1->val != node2->val) return false;
        else return func(node1->left, node2->right) && func(node1->right, node2->left);
    }
};
