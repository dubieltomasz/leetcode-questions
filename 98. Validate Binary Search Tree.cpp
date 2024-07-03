class Solution {
public:
    bool isValidBST(TreeNode* root, const long& minVal = -LONG_MAX, const long& maxVal = LONG_MAX) {
        if(!root) return true;
        else if(minVal >= root->val || root->val >= maxVal) return false;
        else return isValidBST(root->left, minVal, root->val) && isValidBST(root->right, root->val, maxVal);
    }
};
