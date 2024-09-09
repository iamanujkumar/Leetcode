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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // Initialize the matrix with -1
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // Initialize boundaries
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        
        ListNode* curr = head;
        
        // Loop while there are boundaries to consider
        while (top <= bottom && left <= right) {
            // Traverse from left to right across the top boundary
            for (int i = left; i <= right && curr != nullptr; ++i) {
                matrix[top][i] = curr->val;
                curr = curr->next;
            }
            ++top;  // Move the top boundary down

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom && curr != nullptr; ++i) {
                matrix[i][right] = curr->val;
                curr = curr->next;
            }
            --right;  // Move the right boundary left

            // Traverse from right to left across the bottom boundary
            if (top <= bottom) {
                for (int i = right; i >= left && curr != nullptr; --i) {
                    matrix[bottom][i] = curr->val;
                    curr = curr->next;
                }
                --bottom;  // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left boundary
            if (left <= right) {
                for (int i = bottom; i >= top && curr != nullptr; --i) {
                    matrix[i][left] = curr->val;
                    curr = curr->next;
                }
                ++left;
            }
        }
        
        return matrix;
    }
};
