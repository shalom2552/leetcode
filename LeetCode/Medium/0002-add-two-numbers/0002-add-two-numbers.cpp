/**
 * Motivation: Linked List Traversal.
 *     Make a dummy head to easily start building our result list.
 *     Loop while there are nodes left in l1 or l2, or if we still have a carry left.
 *     Add the values from l1 and l2 if they exist, and move them to the next node.
 *     Make a new node with the last digit of our sum (cur % 10).
 *     Move our sum pointer forward and update the carry for the next loop (cur / 10).
 * Complexity: 
 *     Time - O(max(n, m)): We loop through the longest list (lengths n and m).
 *     Space - O(max(n, m)): The new linked list will be at most the size of the longest list plus 1.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        // save a pointer to the sum head
        ListNode* res = new ListNode();
        // pointer to curr sum node
        ListNode* sum_node = res;
        // current digit sum
        int cur = 0;

        // add the lists by digits and construct the sum list on the fly
        while (l1 || l2 || cur) {
            
            // add l1 if it didn't reached the end
            if (l1) {
                cur += l1->val;
                l1 = l1->next;
            }

            // add l2 if it didn't reached the end
            if (l2) {
                cur += l2->val;
                l2 = l2->next;
            }

            // create a new node with the current base 10 sum digit
            ListNode* digit = new ListNode(cur % 10);

            // attach the new node and advance to it
            sum_node->next = digit;
            sum_node = sum_node->next;
            
            // update current sum with the reminder
            cur /= 10;
        }

        // the sum starts from second node
        return res->next;
    }
};
