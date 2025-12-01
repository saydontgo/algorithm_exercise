#include <iostream>
#include <vector>
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

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode*> tmp;
    vector<vector<int>> res;

    if (root != nullptr) {
        tmp.push(root);
    }

    while (!tmp.empty()) {
        vector<int> layer;
        auto size = tmp.size();
        for (int i = 0; i < size; i++) {
            auto node = tmp.front();
            layer.push_back(tmp.front()->val);
            if (node->left != nullptr) {
                tmp.push(node->left);
            }

            if (node->right != nullptr) {
                tmp.push(node->right);
            }
            tmp.pop();
        }
        res.push_back(layer);
    }
    return res;
}
int main() {
    return 0;
}