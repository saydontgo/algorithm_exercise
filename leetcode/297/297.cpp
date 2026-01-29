#include <queue>
#include <string>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Codec {
public:

    string int2str(int val) {
        if (val == 0) { return "0"; }
        string res = "";
        int flag = 0;
        if (val < 0) {
            val = -val;
            flag = 1;
        }
        while (val > 0) {
            res += (val % 10) + '0';
            val /= 10;
        }
        if (flag) { res += '-'; }

        reverse(res.begin(), res.end());
        return res;
    }

    int str2int(string val) {
        int flag = 0;

        if (val[0] == '-') { flag = 1; }

        int res = 0;
        for (int i = flag; i < val.size(); i++) {
            res = res * 10 + (val[i] - '0');
        }
        if (flag) { res = -res; }
        return res;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";

        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto cur = nodes.front();
            nodes.pop();
            if (!cur) {
                res += "n";
            } else {
                res += int2str(cur->val);
                nodes.push(cur->left);
                nodes.push(cur->right);
            }
            res += "#";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) { return nullptr; }

        int size = 2;
        int index = 0;
        queue<int> cur_val;
        queue<TreeNode*> prev_layer;
        TreeNode* root = nullptr;
        string tmp = "";
        while (data[index] != '#') {
            tmp += data[index++];
        }
        index++;
        if (tmp != "n") {
            root = new TreeNode(str2int(tmp));
            prev_layer.push(root);
        }
        while (index < data.size()) {
            for (int i = 0; i < size; i++) {
                string tmp = "";
                while (data[index] != '#') {
                    tmp += data[index++];
                }
                index++;
                if (tmp == "n") {
                    cur_val.push(1001);
                } else {
                    cur_val.push(str2int(tmp));
                }
            }
            size = 0;
            while (!cur_val.empty()) {
                auto cur_node = prev_layer.front();
                prev_layer.pop();

                int left = cur_val.front();
                cur_val.pop();

                int right = cur_val.front();
                cur_val.pop();
                if (left == 1001) {
                    cur_node->left = nullptr;
                } else {
                    cur_node->left = new TreeNode(left);
                    prev_layer.push(cur_node->left);
                    size += 2;
                }
                if (right == 1001) {
                    cur_node->right = nullptr;
                } else {
                    cur_node->right = new TreeNode(right);
                    prev_layer.push(cur_node->right);
                    size += 2;
                }
            }
        }
        return root;
    }
};