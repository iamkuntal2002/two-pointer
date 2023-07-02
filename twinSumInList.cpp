#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
    ListNode *getMid(ListNode *head){
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            // fast = fast->next;
            // if(fast->next != NULL) 
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *reverse(ListNode *head){
        ListNode *curr = head;
        ListNode *prev = NULL, *next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        ListNode *mid = getMid(head);
        ListNode *first = head;
        ListNode *second = reverse(mid->next);
        mid->next = NULL;
        int ans = 0;
        while(first && second){
            ans = max(ans,first->val+second->val);
            first = first->next;
            second = second->next;
        }
        return ans;
    }
};