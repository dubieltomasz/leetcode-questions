class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, const int& target) {
        if(!root) return nullptr;
        
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);

        return (!root->left && !root->right && root->val == target) ? nullptr : root;
    }
};
