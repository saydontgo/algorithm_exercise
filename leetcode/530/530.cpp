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

int getMinimumDifference(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {
        return 1e7;
    }
    int arr[4];

    for (int i = 0; i < 4; i++) {
        arr[i] = 1e7;
    }
    if (root->left != nullptr) {
        auto cursor = root->left;
        while(cursor->right != nullptr) {
            cursor = cursor->right;
        }
        arr[0] = root->val - cursor->val;
        arr[2] = getMinimumDifference(root->left);
    }
    if (root->right != nullptr) {
        auto cursor = root->right;
        while(cursor->left != nullptr) {
            cursor = cursor->left;
        }
        arr[1] = cursor->val - root->val;
        arr[3] = getMinimumDifference(root->right);
    }
    int min = 1e8;
    for (int i = 0; i < 4; i++) {
        if (min > arr[i]) { min = arr[i]; }
    }
    return min;
}
int main() {
    return 0;
}