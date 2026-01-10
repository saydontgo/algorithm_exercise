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
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) { return nullptr; }

        TreeNode* root = new TreeNode(0);
        queue<TreeNode*> tree1;
        queue<TreeNode*> tree2;
        queue<TreeNode*> tree;
        tree1.push(root1);
        tree2.push(root2);
        tree.push(root);

        while (!tree1.empty() && !tree2.empty()) {
            auto cur1 = tree1.front();
            auto cur2 = tree2.front();
            auto cur = tree.front();
            tree1.pop();
            tree2.pop();
            tree.pop();

            if (cur1 == nullptr || cur2 == nullptr) {
                cur->val = cur1 == nullptr ? cur2->val : cur1->val;
            } else {
                cur->val = cur1->val + cur2->val;
            }

            // 处理左节点
            auto cur1_left = cur1 == nullptr? nullptr : cur1->left;
            auto cur2_left = cur2 == nullptr? nullptr : cur2->left;

            if (cur1_left != nullptr || cur2_left != nullptr) {
                cur->left = new TreeNode(0);
                tree.push(cur->left);
                tree1.push(cur1_left);
                tree2.push(cur2_left);
            }

            // 右节点
            auto cur1_right = cur1 == nullptr? nullptr : cur1->right;
            auto cur2_right = cur2 == nullptr? nullptr : cur2->right;

            if (cur1_right != nullptr || cur2_right != nullptr) {
                cur->right = new TreeNode(0);
                tree.push(cur->right);
                tree1.push(cur1_right);
                tree2.push(cur2_right);
            }
        }
        return root;
    }
};