/**
 * Motivation: Recursive reversal.
 *     Recurse to the tail of the list, then rewire each node's next
 *     pointer backwards on the way up. The tail becomes the new head.
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
        if (!head || !head->next) {
            return head;
        }

        ListNode* tail = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return tail;
    }
};
