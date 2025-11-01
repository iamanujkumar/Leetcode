class Solution {
public:
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        while (head != nullptr && numSet.count(head->val)) {
            head = head->next;
        }
        if (head == nullptr) return nullptr;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr != nullptr) {
            if (numSet.count(curr->val)) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }

        return head;
    }
};
