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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head->next) {
            return head;
        }

        int idx = 1;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = curr->next;
        ListNode* prev_left = prev;
        ListNode* left_node = curr;

        // reverse until right
        while (idx <= right) {
            next = curr->next;

            // reverse in the range
            if (idx >= left) {
                curr->next = prev;
            }

            prev = curr;
            curr = next;
            ++idx;

            if (idx == left) {
                prev_left = prev;
                left_node = curr;
            }
        }

        // connect edges
        left_node->next = next;
        if (left > 1) {
            prev_left->next = prev;
            return head;
        } else {
            return prev;
        }
    }
};

