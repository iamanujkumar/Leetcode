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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    if (len == n) {
        return head->next;
    }
    temp = head;
    int count = 1;
    while (count < len - n) {
        temp = temp->next;
        count++;
    }
    temp->next = temp->next->next;

    return head;
}

};