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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyNode = new ListNode(-1);

        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* current = dummyNode;
        while(t1 != NULL && t2 != NULL){
            if(t1->val <= t2->val){
                current->next = t1;
                current = t1;
                t1 = t1->next;
            }
            else{
                current->next = t2;
                current = t2;
                t2 = t2->next;
            }
        }
        if(t1) current->next = t1;
        else current->next = t2;
        return dummyNode->next;
    }
};