#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;
class MinStack {
public:
    MinStack() : min(INT32_MAX) {
        
    }
    
    void push(int val) {
      if (min > val) { min = val; }
      stack.push_back(val);
    }
    
    void pop() {
      auto to_be_deleted = top();
      stack.pop_back();
      if (to_be_deleted == min) {
        min = INT32_MAX;
        for (const auto &ele : stack) {
          if (ele < min) { min = ele; }
        }
      }
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int getMin() {
        return min;
    }
private:
    vector<int> stack;
    int min;
};
int main() {
  return 0;
}