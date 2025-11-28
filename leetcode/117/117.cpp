#include <iostream>
#include <deque>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    deque<Node*> layer;

    if (root != nullptr) {
        layer.push_back(root);
    }
    while (!layer.empty()) {
        auto size = layer.size();
        for (int i = 0; i < size; i++) {
            if (layer[0]->left != nullptr) { layer.push_back(layer[0]->left); }
            if (layer[0]->right != nullptr) { layer.push_back(layer[0]->right); }
            if (i < size - 1) {
                layer[0]->next = layer[1];
            }
            layer.pop_front();
        }
    }
    return root;
}
int main() {
    return 0;
}