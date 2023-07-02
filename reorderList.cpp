#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/reorder-list/


    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

Node<int> *reverse(Node<int> *head){
    // if(head == NULL) return NULL;
    Node<int>* curr = head;
    Node<int>* next = NULL;
    Node<int>* prev = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
Node<int>* rearrangeList(Node<int>* head)
{
    // Write your code here.
    if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
    Node<int> *fast = head, *slow = head, *prev = head;
    while(fast->next != NULL && fast->next->next != NULL){
        // prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    // prev->next = NULL;
    Node<int> *first = head, *temp1, *temp2;
    Node<int> *second = NULL;
    second = reverse(slow->next);
    slow->next =NULL;
    Node<int> *res = head;
    Node<int> *curr = res;
    // return NULL;
    while(first && second){
        temp1 = first->next;
        temp2 = second->next;    
        first->next=second;
        second->next=temp1;
        second=temp2;
        first=temp1;
    }
    // if(first != NULL) curr->next = first;
    if(second != NULL) first->next = second;
    return res;
}