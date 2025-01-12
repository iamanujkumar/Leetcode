/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
int getLength(ListNode* head) {
    int count = 0;
    ListNode* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}
   ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int n1 = getLength(headA);
    int n2 = getLength(headB);
    while (n1 > n2) {
        headA = headA->next;
        n1--;
    }
    while (n2 > n1) {
        headB = headB->next;
        n2--;
    }
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}

};