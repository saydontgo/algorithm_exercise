#include <vector>
#include <queue>
#include <stack>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) { return res; }

        queue<TreeNode*> layer;
        layer.push(root);
        int flag = 1;
        while (!layer.empty()) {
            vector<int> tmp;
            stack<TreeNode*> ceng;
            while (!layer.empty()) {
                auto tar = layer.front();
                tmp.push_back(tar->val);
                ceng.push(layer.front());
                layer.pop();
            }
            res.push_back(tmp);

            while (!ceng.empty()) {
                auto tar = ceng.top();
                if (!flag) {
                    if (tar->left != nullptr)
                      layer.push(tar->left);
                    if (tar->right != nullptr)
                      layer.push(tar->right);
                } else {
                     if (tar->right != nullptr)
                      layer.push(tar->right);
                    if (tar->left != nullptr)
                      layer.push(tar->left);
                }
                ceng.pop();
            }
            flag = !flag;
        }
        return res;
    }
};