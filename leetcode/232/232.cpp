#include <iostream>
#include <stack>
using namespace std;

// 均摊为O(1)
class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        left.push(x);
    }
    
    int pop() {
        if (right.empty()) {
            left2right();
        }
        auto res = right.top();
        right.pop();
        return res;
    }
    
    int peek() {
        if (right.empty()) {
            left2right();
        }
        return right.top();
    }
    
    bool empty() {
        return right.empty() && left.empty();
    }
private:
    stack<int> left;
    stack<int> right;

    void left2right() {
        while (!left.empty()) {
            right.push(left.top());
            left.pop();
        }
    }
};

// push 为 O(n), 其他为O(1)
// class MyQueue {
// public:
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         while (!right.empty()) {
//             left.push(right.top());
//             right.pop();
//         }
//         left.push(x);
//         while (!left.empty()) {
//             right.push(left.top());
//             left.pop();
//         }
//     }
    
//     int pop() {
//         auto res = right.top();
//         right.pop();
//         return res;
//     }
    
//     int peek() {
//         return right.top();
//     }
    
//     bool empty() {
//         return right.empty();
//     }
// private:
//     stack<int> left;
//     stack<int> right;
// };

int main() {
    return 0;
}