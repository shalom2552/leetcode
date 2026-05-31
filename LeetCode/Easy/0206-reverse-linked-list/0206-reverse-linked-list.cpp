/*
 * Motivation: Iterative reversal.
 *     Loop over the list and reverse each node's next pointer to point
 *     to the previous node. Return the last node as the new head.
 *     If the list was empty the while wont run and empty prev will return.
 * Complexity: 
 *     Time - O(n): Visit each node once.
 *     Space - O(1): Auxiliary.
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
        ListNode* prev = nullptr;

        while (head) {

            ListNode* next = head->next;
            head->next = prev;

            prev = head;
            head = next;
        }

        return prev; // new head
    }
};