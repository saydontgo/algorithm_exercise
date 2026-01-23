#include <vector>
#include <unordered_set>
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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) { return vector<int>(); }
        unordered_set<TreeNode*> added;
        vector<TreeNode*> layer;

        layer.push_back(root);
        int prev = 0;
        int len = 1;

        while (len != prev) {
            prev = len;
            vector<TreeNode*> tmp;

            for (const auto& node : layer) {
                if (added.count(node)) {
                    tmp.push_back(node);
                    continue;
                }
                added.insert(node);
                if (node->left != nullptr) {
                    tmp.push_back(node->left);
                    len++;
                }
                tmp.push_back(node);
                if (node->right != nullptr) {
                    tmp.push_back(node->right);
                    len++;
                }
            }
            layer = tmp;
        }
        vector<int> inorder;
        for (const auto& node : layer) {
            inorder.push_back(node->val);
        }
        return inorder;
    }
};