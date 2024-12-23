class Solution {
public:
    int minimumOperations(TreeNode* root) {
        int answer = 0;

        func(root, 0);

        for(std::vector<int>& level : levels)
        {
            bool loop = true;
            std::vector<int> sorted = level;
            std::sort(sorted.begin(), sorted.end());

            while(loop)
            {
                loop = false;

                for(int i = 0; i < level.size(); ++i)
                {
                    if(level[i] != sorted[i])
                    {
                        loop = true;
                        ++answer;
                        int l = 0, r = sorted.size()-1;

                        while(true)
                        {
                            int m = l + (r - l >> 1);

                            if(sorted[m] == level[i])
                            {
                                std::swap(level[i], level[m]);
                                break;
                            }
                            else if(sorted[m] < level[i]) l = m + 1;
                            else r = m - 1;
                        }
                    }
                }
            }
        }

        return answer;
    }

private:
    std::vector<std::vector<int>> levels;

    void func(TreeNode* node, int level)
    {
        if(levels.size() <= level)
            levels.push_back({});
    
        levels[level].push_back(node->val);

        if(node->left) func(node->left, level+1);
        if(node->right) func(node->right, level+1);
    }
};
