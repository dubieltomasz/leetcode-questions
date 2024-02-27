class Solution {
private:
    int answer = 0;

    int func(const TreeNode* node)
    {
        if(!node) return 0;
        else
        {
            int left = func(node->left);
            int right = func(node->right);

            if(left+right > answer) answer = left+right;

            return (left > right)? left+1 : right+1;
        }
    }

public:
    int diameterOfBinaryTree(const TreeNode* root) {
        func(root);

        return answer;
    }
};
