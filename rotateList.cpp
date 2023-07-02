#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/rotate-list/

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        
        int len=1; 
        ListNode *newNode, *tail;
        newNode=tail=head;        
        while(tail->next != NULL)  
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; 
        if(k %= len) {            
               
            for(auto i=0; i<len-k; i++)
                tail = tail->next; 
        }
        newNode = tail->next; 
        tail->next = NULL;
        return newNode;
    }
};