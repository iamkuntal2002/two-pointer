#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-nth-node-from-end-of-list

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        ListNode *temp = new ListNode(-1);
        temp->next = head;
        ListNode *slow = temp, *fast = temp;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        while (fast->next) 
        {
            fast = fast->next;
            slow = slow->next;
        }
        // ListNode *nthnode = slow->next;
        slow->next = slow->next->next;
        return temp->next;
        
    }
};

// -1 -> 1 -> 2 -> 3 -> 4 -> 5
//          fast
//                 slow        fast



