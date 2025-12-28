#include <iostream>
#include <vector>

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
 typedef long long ll;
    void dfs(TreeNode* root, ll targetSum, vector<ll>& tmp, ll& res) {
        if (root == nullptr) { return; }

        dfs(root->left, targetSum, tmp, res);
        vector<ll> right_tmp;
        dfs(root->right, targetSum, right_tmp, res);
        tmp.push_back(0);
        for (ll i = 0; i < tmp.size(); i++) {
            tmp[i] += root->val;
            if (tmp[i] == targetSum) {
                res++;
            }
        }
        for (ll i = 0; i < right_tmp.size(); i++) {
            tmp.push_back(right_tmp[i] + root->val);
            if (right_tmp[i] + root->val == targetSum) {
                res++;
            }
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        ll res = 0;
        vector<ll> tmp;
        dfs(root, targetSum, tmp, res);
        return res;
    }
};
int main() {
  return 0;
}