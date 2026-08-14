class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* current = root;
        while (current) {
            if (current->left) {
                TreeNode* temp = current->left;
                while (temp->right) {
                    temp = temp->right;
                }
                temp->right = current->right;
                current->right = current->left;
                current->left = nullptr;
            }
            current = current->right;
        }
    }
};