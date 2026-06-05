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
ListNode* findNthNode(ListNode* temp, int k){
    int c = 1;
    while(temp != NULL){
        if(c == k) return temp;
        c++;
        temp = temp->next;
    }
    return temp;
}
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 1;
        if(head == NULL || k == 0) return head;
        ListNode* tail = head;
        while(tail->next != NULL){
            count++;
            tail = tail->next;
        }
        if(k % count == 0){
            return head;
        }
        k = k % count;
        tail->next = head;
        ListNode* newLastNode = findNthNode(head, count-k);
        head = newLastNode->next;
        newLastNode->next = NULL;

        return head; 
    }
        
};