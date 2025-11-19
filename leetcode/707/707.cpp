#include <iostream>
using namespace std;

struct node {
    int val_;
    node* next_;
    node();
    node(int val): val_(val), next_(nullptr) {}
    node(int val, node* next): val_(val), next_(next) {}
};
class MyLinkedList {
public:
    MyLinkedList() {
    }
    
    int get(int index) {
        auto cursor = head_;
        int pos = 0;
        while (cursor != nullptr) {
            if (pos == index) { return cursor->val_; }
            cursor = cursor->next_;
            pos++;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        head_ = new node(val, head_);
    }
    
    void addAtTail(int val) {
        node* prev = nullptr;
        auto cursor = head_;
        while (cursor != nullptr) {
            prev = cursor;
            cursor = cursor->next_;
        }

        if (prev) {
            prev->next_ = new node(val);
        } else {
            head_ = new node(val, head_);
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }
        auto cursor = head_;
        int pos = 0;
        while (cursor != nullptr) {
            if (pos == index - 1) {
                auto tmp = cursor->next_;
                cursor->next_ = new node(val, tmp);
                return;
            }
            cursor = cursor->next_;
            pos++;
        }
    }
    
    void deleteAtIndex(int index) {
        node* prev = nullptr;
        auto cursor = head_;
        int pos = 0;
        while (cursor != nullptr) {
            if (pos == index) {
                auto tmp = cursor->next_;
                delete cursor;
                if (prev == nullptr) {
                    head_ = tmp;
                } else {
                    prev->next_ = tmp;
                }
                return;
            }
            prev = cursor;
            cursor = cursor->next_;
            pos++;
        }
    }
private:
    node* head_{nullptr};
};

int main() {
    return 0;
}