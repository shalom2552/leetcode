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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    // save root to result so we can return it
    ListNode* cur = nullptr;
    ListNode* result = cur;

    // while there is elements in the list
    bool finished = false;
    while (! finished ) {
        // assume we finished until found otherwise
        finished = true;

        // initialize min variables for each iteration
        int min = INT_MIN;
        ListNode** min_list = nullptr;
        
        // find the next min element
        for (ListNode*& list : lists) {
            
            // list is empty
            if (list == nullptr) {
                continue;
            }

            // found non empty list
            finished = false;

            // ccheck if this is the first value in the current iteration
            if (min == INT_MIN || min > list->val) {
                // update min and progress list
                min = list->val;
                min_list = &list;
            }
        }

        // no more elements
        if (min == INT_MIN) {
            continue;
        }

        // if this is the first found element then initialize root
        if (cur == nullptr) {
            // create new root with the first min value
            cur = new ListNode(min);
            // keep pointer to the root
            result = cur;
        } else {
            // create new node from current and progress
            cur->next = new ListNode(min);
            cur = cur->next;
        }

        // progress with the corresponding list
        *min_list = (*min_list)->next;
    }

    return result;        
}

};