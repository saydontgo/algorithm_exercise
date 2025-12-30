struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    void dfs(TreeNode* root, TreeNode*& cursor) {
        if (root == nullptr) {
            return;
        }
        auto left = root->left;
        auto right = root->right;

        root->left = nullptr;
        cursor->right = root;
        cursor = root;
        dfs(left, cursor);
        dfs(right, cursor);
        return;
    }
    void flatten(TreeNode* root) {
        TreeNode dummy;
        auto tmp = &dummy;
        dfs(root, tmp);
    }
};