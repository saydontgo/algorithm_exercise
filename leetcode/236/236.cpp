#include <iostream>
#include <deque>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void dfs(TreeNode* root, TreeNode* target, deque<TreeNode*>& res) {
    if (root == nullptr) { return; }

    res.push_back(root);
    if (target == root) {
        return;
    }

    dfs(root->left, target, res);
    dfs(root->right, target, res);

    if (!res.empty() && res[res.size() - 1] != target) {
        res.pop_back();
    }
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    deque<TreeNode*> left;
    deque<TreeNode*> right;
    dfs(root, p, left);
    dfs(root, q, right);
    auto left_size = left.size() - 1;
    auto right_size = right.size() - 1;

    for (int i = right_size; i > -1; i--) {
        for (int j = left_size; j > -1; j--) {
            if (right[i] == left[j]) {
                return left[i];
            }
        }
    }
    return nullptr;
}
int main() {
    return 0;
}