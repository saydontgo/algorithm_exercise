#include <iostream>
using namespace std;
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
    int dfs(TreeNode* root, int& res) {
        if (root == nullptr) { return 0; }

        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        int left_edge = 1;
        int right_edge = 1;

        if (root->left == nullptr) {
            left_edge = 0;
        }
        if (root->right == nullptr) {
            right_edge = 0;
        }
        res = max(res, left + right + left_edge + right_edge);

        return max(left + left_edge, right + right_edge);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }
};