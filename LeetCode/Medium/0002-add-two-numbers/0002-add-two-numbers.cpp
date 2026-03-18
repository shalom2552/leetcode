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
            
            // update current sum
            cur /= 10;
        }

        // the sum starts from second node
        return res->next;
    }
};
