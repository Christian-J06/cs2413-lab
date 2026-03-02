// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode hold;
    hold.val = 0;
    hold.next = head;
    
    struct ListNode* prev = &hold;
    struct ListNode* first;
    struct ListNode* second;
    
    while (prev->next && prev->next->next) {
      first = prev->next;
      second = prev->next->next;
        
        
      prev->next = second;
      first->next = second->next;
      second->next = first;
        
      prev = first;
    }
    
    return hold.next;
}