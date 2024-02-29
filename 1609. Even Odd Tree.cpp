class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool evenLevel = true;

        while(!q.empty())
        {
            int size = q.size();
            TreeNode* node;
            int previous;

            if(evenLevel)
            {
                previous = 0;

                while(size--)
                {
                    node = q.front();
                    q.pop();

                    if(node->val % 2 == 0 || previous >= node->val) return false;
                    previous = node->val;

                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
            else
            {
                previous = INT_MAX;

                while(size--)
                {
                    node = q.front();
                    q.pop();

                    if(node->val % 2 != 0 || previous <= node->val) return false;
                    previous = node->val;

                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }            

            evenLevel = !evenLevel;
        }

        return true;
    }
};
