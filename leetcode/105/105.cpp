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

TreeNode* buildTreeHelp(vector<int>& preorder, vector<int>& inorder, int start, int end, int index) {
    if (end < start) { return nullptr; }
    TreeNode* head = new TreeNode(preorder[index]);

    for (int i = start; i <= end; i++) {
        if (inorder[i] == preorder[index]) {
            head->left = buildTreeHelp(preorder, inorder, start, i - 1, index + 1);
            head->right = buildTreeHelp(preorder, inorder, i + 1, end, i - start + 1 + index);
            break;
        }
    }
    return head;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int end = inorder.size() - 1;
    return buildTreeHelp(preorder, inorder, 0, end, 0);
}
int main() {
    return 0;
}