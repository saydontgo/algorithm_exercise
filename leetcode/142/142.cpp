#include <cstddef>
#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
  auto fast = head;
  auto slow = head;
  
  while (fast != nullptr) {
    fast = fast->next;
    if (fast == nullptr) { return nullptr; }
    fast = fast->next;
    slow = slow->next;
    if (slow == fast) {
      auto ptr = head;
      while(ptr != slow) {
        slow = slow->next;
        ptr = ptr->next;
      }
      return ptr;
    }
  }
  return nullptr;
}


int main() {
  return 0;
}