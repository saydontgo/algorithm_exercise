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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        deque<pair<unsigned long long, TreeNode*>> layer;

        layer.push_back({0, root});

        while (!layer.empty()) {
            int size = layer.size();
            for (int i = 0; i < size; i++) {
                auto cur = layer.front();
                layer.pop_front();
                if (cur.second->left) {
                    layer.push_back({cur.first * 2 + 1, cur.second->left});
                }
                if (cur.second->right) {
                    layer.push_back({cur.first * 2 + 2, cur.second->right});
                }
            }
            if (layer.empty()) { break; }
            res = max(layer[layer.size() - 1].first - layer[0].first + 1, res);
        }
        return res;
    }
};