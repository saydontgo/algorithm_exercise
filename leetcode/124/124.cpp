/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
        // 返回以root为起点的最大贡献值
        if (root == nullptr) {
            return 0;
        }
        auto left = dfs(root->left, res);
        auto right = dfs(root->right, res);
        res = max(res, root->val);
        res = max(res, root->val + left);
        res = max(res, root->val + right);
        res = max(res, root->val + left + right);
        
        int re_val = root->val;
        int max_val = left > right ? left : right;
        return max_val > 0 ? re_val + max_val : re_val;
    }
    int maxPathSum(TreeNode* root) {
        int res = -1e6;
        dfs(root, res);
        return res;
    }
};