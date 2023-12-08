class Solution {
public:
    string tree2str(TreeNode* root) {
        return to_string(root->val) +
            (
                root->left != nullptr?
                    root->right != nullptr?
                        "("+tree2str(root->left)+")("+tree2str(root->right)+")" : "("+tree2str(root->left)+")"
                : root->right != nullptr?
                    "()("+tree2str(root->right)+")" : ""
            );
    }       
};
