/*
 * Motivation: Recursive reversal.
 *     Reverse each node's next pointer to point to the previous node.
 *     Pass the previous and current nodes recursively until the end.
 * Complexity: 
 *     Time - O(n): Visit each node once.
 *     Space - O(n): Recursion stack.
 * 
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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
        return reverseHelper(nullptr, head);
    }

    ListNode* reverseHelper(ListNode* prev, ListNode* curr) {
        if (!curr) {
            return prev;
        }

        ListNode* next = curr->next;
        curr->next = prev;

        return reverseHelper(curr, next);
    }
};