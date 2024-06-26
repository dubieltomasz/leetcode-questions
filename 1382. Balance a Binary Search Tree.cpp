class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        treeToVector(root);

        return createTree(0, inorder.size()-1);
    }

private:
    vector<int> inorder;

    void treeToVector(TreeNode* node)
    {
        if(!node) return;

        treeToVector(node->left);
        inorder.push_back(node->val);
        treeToVector(node->right);        
    }

    TreeNode* createTree(const int& left, const int& right)
    {
        if(left > right) return nullptr;
        
        int mid = (left+right)/2;

        TreeNode* leftSubTree = createTree(left, mid-1);
        TreeNode* rightSubTree = createTree(mid+1, right);

        return new TreeNode(inorder[mid], leftSubTree, rightSubTree);
    }
};
