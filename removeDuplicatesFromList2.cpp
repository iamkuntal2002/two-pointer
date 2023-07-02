#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        stack<ListNode*> st;
        ListNode *curr = head, *popped = NULL;
        while(curr != NULL){
            ListNode *peek = NULL;
            if(!st.empty()) peek = st.top();
            if(popped != NULL && popped->val == curr->val){
                curr = curr->next;
                continue;
            }
            if(peek != NULL && peek->val == curr->val){
                popped = st.top();
                st.pop();
                curr = curr->next;
                continue;
            }
            st.push(curr);
            curr = curr->next;
        }
        ListNode *res = NULL;
        while(!st.empty()){
            popped = st.top();
            st.pop();
            popped->next = res;
            res = popped;
        }
        return res;
    }
};