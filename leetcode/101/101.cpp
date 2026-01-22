#include <deque>
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
    bool isSymmetric(TreeNode* root) {
        deque<TreeNode*> layer;

        layer.push_back(root);

        while (!layer.empty()) {
            for (int i = 0; i < layer.size() - i; i++) {
                
                if (layer[i] && layer[layer.size() - 1 - i]) {
                    if (layer[i]->val != layer[layer.size() - 1 - i]->val) {
                        return false;
                    }
                } else if (layer[i] || layer[layer.size() - 1 - i]) {
                    return false;
                }
            }
            deque<TreeNode*> tmp;

            while (!layer.empty()) {
                auto cur = layer.front();
                layer.pop_front();
                if (!cur) { continue; }
                tmp.push_back(cur->left);
                tmp.push_back(cur->right);
            }
            layer = tmp;
        }
        return true;
    }
};