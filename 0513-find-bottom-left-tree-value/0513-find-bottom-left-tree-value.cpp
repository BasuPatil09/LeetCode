class Solution {
public:
    int value = -1;
    int curr = -1;

    void travel(TreeNode* root, int level) {
        if (!root) {
            return;
        }

        if (level > curr) {
            curr = level;
            value = root->val;
        }

        travel(root->left, level + 1);
        travel(root->right, level + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        value = root->val;
        travel(root, 0);
        return value;
    }
};