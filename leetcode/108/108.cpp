#include <iostream>
#include <vector>
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

TreeNode* GetSubTree(vector<int>& nums, int start, int end) {
    if (start >= end) {
        auto res = new TreeNode(nums[start]);
        return res; 
    }
    auto middle = (start + end) / 2;

    auto left_end = middle - 1;
    auto right_start = middle + 1;
    TreeNode * tree = nullptr;
    if (left_end < start) {
        tree = new TreeNode(nums[middle], nullptr, GetSubTree(nums, right_start, end));
    }
    else {
        tree = new TreeNode(nums[middle], GetSubTree(nums, start, left_end), GetSubTree(nums, right_start, end));
    }
    return tree;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    auto size = nums.size();
    return GetSubTree(nums, 0, size - 1);
}

void test() {
    auto nums = vector<int>({1,3});
    auto res = sortedArrayToBST(nums);
    deque<TreeNode*> nodes;
    nodes.push_back(res);
    while(!nodes.empty()) {
        auto tmp = nodes.front();
        nodes.pop_front();
        if (tmp == nullptr) {
            cout << "null ";
            continue;
        }
        cout << tmp->val << " ";
        if (tmp->left == nullptr && tmp->right == nullptr) { continue; }
        nodes.push_back(tmp->left);
        nodes.push_back(tmp->right);
    }
}
int main() {
    test();
    return 0;
}