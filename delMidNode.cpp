#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) {
            head = NULL;
            return head;
        }
        ListNode *slow = head, *fast = head,*temp = head;
        while(fast && fast->next){
            if(slow != head) temp = temp->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = slow->next;
        return head;
    }
};