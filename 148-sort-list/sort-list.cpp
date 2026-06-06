/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeTwoLists(ListNode *h1, ListNode *h2){
        ListNode* dummyN = new ListNode(-1);
        ListNode* temp = dummyN;
        while(h1 != NULL && h2 != NULL){
            if(h1->val < h2->val){
                temp->next = h1;
                temp = h1;
                h1 = h1->next;
            }
            else{
                temp->next = h2;
                temp = h2;
                h2 = h2->next;
            }
        }
        if(h1) temp->next = h1;
        else temp->next = h2;

        return dummyN->next;
    }
    ListNode* sortList(ListNode* head) {
         if(head == NULL || head->next == NULL) return head;
         ListNode* middle = findMiddle(head);
         ListNode* right = middle->next;
         middle->next = NULL;
         ListNode* left = head;
         left = sortList(left);
         right = sortList(right);
         return mergeTwoLists(left, right);
    }
};