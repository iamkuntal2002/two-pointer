#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/partition-list/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *smaller = new ListNode(-1);
        ListNode *greater = new ListNode(-1);
        ListNode * smallercurr = smaller;
        ListNode * greatercurr = greater;
        while(head != NULL){
            if(head->val < x){
                smallercurr->next = head;
                smallercurr = smallercurr->next;
            }
            else{
                greatercurr->next = head;
                greatercurr = greatercurr->next;
            }
            head = head->next;
        }
        greatercurr->next = NULL;
        smallercurr->next = greater->next;
        return smaller->next;
    }
};