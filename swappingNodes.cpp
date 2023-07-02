#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

class Solution {
public:
      ListNode* swapNodes(ListNode* head, int k) {
        ListNode * temp1 = head;
        ListNode * temp2 = head;
        ListNode * kth = NULL;
        for(int i = 1; i< k;i++){
            temp1 = temp1->next;
        }
        kth = temp1;
        temp1 = temp1->next;
        while(temp1 ){
            temp1 =temp1->next;
            temp2 = temp2->next;
        }
        int kthval =  kth->val;
        kth->val = temp2->val;
        temp2->val = kthval;
        return head;
    }
};