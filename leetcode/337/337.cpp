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
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, 0};
        }
        if (root->left == nullptr && root->right == nullptr) {
            return {root->val, 0};
        }
        auto left_pair = dfs(root->left);
        auto right_pair = dfs(root->right);

        auto second_val = left_pair.first + right_pair.first;
        auto first_val = max(root->val + left_pair.second + right_pair.second, left_pair.first + right_pair.first);
        return {first_val, second_val};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return res.first;
    }
};