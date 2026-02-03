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
    pair<int, int> getMaxMin(TreeNode* root, bool& valid) {
        int min_val = root->val;
        int max_val = root->val;
        if (root->left != nullptr) {
            auto left = getMaxMin(root->left, valid);
            if (left.first >= root->val) { valid = false; }
            min_val = left.second;
        }
        if (root->right != nullptr) {
            auto right = getMaxMin(root->right, valid);
            if (right.second <= root->val) { valid = false; }
            max_val = right.first;
        }
        return {max_val, min_val};
    }
    bool isValidBST(TreeNode* root) {
        bool res = true;
        getMaxMin(root, res);
        return res;
    }
};