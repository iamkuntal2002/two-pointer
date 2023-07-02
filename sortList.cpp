#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/sort-list

  struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2){
        ListNode *temp = new ListNode(0);
        ListNode *curr = temp;
        while(l1 != NULL && l2 != NULL){
            if(l1->val >= l2->val){
                curr->next= l2;
                l2 = l2->next;
            }
            else{
                curr->next = l1;
                l1 = l1->next;
            }
            curr = curr->next;
        }
        if(l1 != NULL) {
            curr->next = l1;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            curr->next = l2;
            l2 = l2->next;
        }
        return temp->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = NULL;
        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode *list1 = sortList(slow);
        ListNode *list2 = sortList(head);
        return merge(list1,list2);

    }
};