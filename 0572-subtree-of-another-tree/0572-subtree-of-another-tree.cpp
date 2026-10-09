
class Solution {
public:

    bool dfs(TreeNode* root, TreeNode* subroot) {
        if (!root && !subroot) {
            return true;
        }

        if (!root || !subroot) {
            return false;
        }

        if (root->val != subroot->val) {
            return false;
        }

        bool temp = dfs(root->left, subroot->left) &&
                    dfs(root->right, subroot->right);

        return temp;
    }

    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if (!root) {
            return false;
        }

        if (dfs(root, subroot)) {
            return true;
        }

        return isSubtree(root->left, subroot) ||
               isSubtree(root->right, subroot);
    }
};