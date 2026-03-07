/*
Motivation: w'ell use a min heap to store all element,
     then we'll extract them to get the sorted list.
     we'll use the priority queue with modified comperator.
Complexity: 
     Time - O(n*log(n)): n times poping from heap, log(n) each.
     Space - O(n): the min_heap and result list.
Where n is the number of elements in all lists combined.
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

    // min heap to store all values initially
    std::priority_queue<int> min_heap;
    
    // push all values into the min heap
    for (ListNode*& list : lists) {
            
        // list is empty
        if (list == nullptr) {
            continue;
        }

        // travers all elements in the list
        while (list != nullptr) {

            // push the negative value for min order
            min_heap.push( (-1) * list->val );
            list = list->next;
        }
    }

    // use a dummy node to keep pointer to root
    ListNode dummy;
    ListNode* cur = &dummy;

    // insert all elements from heap to the list
    while (! min_heap.empty() ) {

        // we stored the values as negative
        int val = (-1) * min_heap.top();
        cur->next = new ListNode(val);
        cur = cur->next;
        min_heap.pop();
    }
  
    // results is a dummy node
    // if no elements where found, dummy.next is nullptr
    return dummy.next;        
}

};

/*  Broute force solution */
class SolutionBF {
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