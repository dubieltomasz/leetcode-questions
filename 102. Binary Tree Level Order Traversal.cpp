class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};

        vector<vector<int>> answer;
        vector<int> level;
        TreeNode* tmp;
        queue<TreeNode*> q;
        size_t size;

        q.push(root);

        while(!q.empty())
        {
            level.clear();

            size = q.size();

            while(size--)
            {
                tmp = q.front();

                level.push_back(tmp->val);

                if(tmp->left) q.push(tmp->left);
                if(tmp->right) q.push(tmp->right);

                q.pop();
            }

            answer.push_back(level);
        }

        return answer;
    }
};
