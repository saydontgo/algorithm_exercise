#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> q;
    if (root == nullptr) { return nullptr; }
    q.push(root);

    while (!q.empty()) {
        auto father = q.front();
        q.pop();
        auto tmp = father->left;
        father->left = father->right;
        father->right = tmp;

        if (father->left != nullptr) { q.push(father->left); }
        if (father->right != nullptr) { q.push(father->right); }
    }

    return root;
}
int main() {
    return 0;
}