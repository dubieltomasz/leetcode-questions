static const void __attribute((constructor)) fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

class Solution {
private:
    int max = -1;

    void func(TreeNode* root, int minAncVal, int maxAncVal)
    {
        if(max < abs(root->val - minAncVal))
            max = abs(root->val - minAncVal);

        if(max < abs(root->val - maxAncVal))
            max = abs(root->val - maxAncVal);

        if(root->val < minAncVal) minAncVal = root->val;
        if(root->val > maxAncVal) maxAncVal = root->val;

        if(root->right != nullptr) func(root->right, minAncVal, maxAncVal);
        if(root->left != nullptr) func(root->left, minAncVal, maxAncVal);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        func(root, root->val, root->val);

        return max; 
    }
};
