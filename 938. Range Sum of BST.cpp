/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 const static int func = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    int rangeSumBST(TreeNode* root, const int& low, const int& high) {
        if(root == nullptr) return 0;
        else return ((root->val >= low && root->val <= high)? root->val : 0) + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }
};
