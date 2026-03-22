/**
 * Motivation: Floyd's Cycle-Finding Algorithm (Two Pointers).
 *     Initialize two pointers, slow and fast, at the beginning of the linked list.
 *     Traverse the list by moving the slow pointer one step and the fast pointer two steps at a time.
 *     If there is a cycle, the fast pointer will eventually catch up to the slow pointer, and they will meet.
 *     If the fast pointer reaches the end of the list (NULL), it means no cycle exists.
 *     This approach allows us to detect the cycle without using any extra memory to store visited nodes.
 * Complexity: 
 *     Time - O(n): In the worst case, we visit each node at most twice.
 *     Space - O(1): Only two pointers are used regardless of the list size.
 *
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // no cycle on empty list
        if (!head) {
            return false;
        }

        // fast takes two steps
        ListNode* slow = head;
        ListNode* fast = head->next;

        // reached to end when fast cannot advance
        while(fast && fast->next) {
            
            // in a cycle fast will meet slow
            if (slow == fast) {
                return true;
            }

            // in a cycle, distance will shring by 1 in each iteration
            slow = slow->next;
            fast = fast->next->next;
        }

        // no cycle found
        return false;
    }
};
