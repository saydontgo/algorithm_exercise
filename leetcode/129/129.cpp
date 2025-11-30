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

void dfs(int& sum, int tmp, TreeNode* cur) {
    if (cur->left == nullptr && cur->right == nullptr) {
        sum += tmp * 10 + cur->val;
        return;
    }

    if (cur->left != nullptr) {
        dfs(sum, tmp * 10 + cur->val, cur->left);
    }
    if (cur->right != nullptr) {
        dfs(sum, tmp * 10 + cur->val, cur->right);
    }
}
int sumNumbers(TreeNode* root) {
    int sum = 0;
    dfs(sum, 0, root);
    return sum;
}
int main() {
    return 0;
}